class Solution {
public:
    
    string decodeString(string s) {
        int i = 0;
        return decode(i,s);
    }
    string decode(int &i,string &s){
        int n = s.size();
        string result = "";
        int num = 0;
        while(i < n){
            char c = s[i];
            if(isdigit(c)){
                num = num*10 + (c - '0');
                i++;
            }
            else if(c == '['){
                i++;
                string inner = decode(i,s);
                for(int k = 0;k<num;k++) result+=inner;
                num = 0;
            }
            else if(c == ']'){
                i++;
                return result;
            }
            else{
                result+=c;
                i++;
            }
        }
        return result;
    }
};

// google interview question


// #include <bits/stdc++.h>
// using namespace std;

// // Recursive function to decode the string starting at index 'i'
// string decode(const string &s, int &i) {
//     string result = "";
    
//     while (i < s.size() && s[i] != ')') {
//         if (s[i] == '(') {
//             i++; // Skip '('
//             string inner = decode(s, i); // Decode inside parentheses
//             i++; // Skip ')'
            
//             int repeat = 0;
//             if (i < s.size() && s[i] == '{') {
//                 i++; // Skip '{'
//                 while (i < s.size() && isdigit(s[i])) {
//                     repeat = repeat * 10 + (s[i] - '0');
//                     i++;
//                 }
//                 i++; // Skip '}'
//             } else {
//                 repeat = 1; // Default repeat count
//             }
            
//             // Append the repeated substring
//             for (int j = 0; j < repeat; j++)
//                 result += inner;
//         } 
//         else {
//             // Normal character, just append
//             result += s[i];
//             i++;
//         }
//     }
//     return result;
// }

// string decompress(string s) {
//     int i = 0;
//     return decode(s, i);
// }

// // Driver function
// int main() {
//     cout << decompress("a(bcd){3}e") << endl;        // Output: "abcdbcdbcde"
//     cout << decompress("a(bc(d){4}e){3}f") << endl;  // Output: "abcddddebcddddebcddddef"
//     return 0;
// }
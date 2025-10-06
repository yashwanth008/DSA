class Solution {
public:
    int longestPalindrome(string s) {
        int oddcount = 0;
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
            if(freq[c]%2 != 0) oddcount++;
            else oddcount--;
        }
       
        if (oddcount>1) return s.length() - oddcount + 1;
        return s.length();
    }
};
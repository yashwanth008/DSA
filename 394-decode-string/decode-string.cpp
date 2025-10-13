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
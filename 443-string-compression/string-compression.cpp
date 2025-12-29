class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
        int pos = 0;
        for(int i = 0;i<n;i++){
            char ch = chars[i];
            int count = 1;
            while(i<n-1 && chars[i] == chars[i+1]){
                i++;
                count++;
            }
            chars[pos] = ch;
            pos++;
            if(count != 1){
                string ct = to_string(count);
                for(char c:ct){
                    chars[pos] = c;
                    pos++;
                }
            }
        }
        
        return pos;
        
    }
};
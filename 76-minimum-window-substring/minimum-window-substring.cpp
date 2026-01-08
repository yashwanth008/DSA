class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0,right = 0;
        int minLen = INT_MAX;
        unordered_map<char,int> charFreq,s_mat;
        int target_size = t.size();
        int debt = 0,newLeft = 0;

        for(char c:t) charFreq[c]++;


        while(right < s.size()){
            char ch = s[right];
            s_mat[ch]++;

            if(charFreq.count(ch) && s_mat[ch] <= charFreq[ch]){
                debt++;
            }
           
            while(debt == target_size){
                if((right-left+1)<minLen){
                    minLen = (right-left+1);
                    newLeft = left;
                }
                char leftchar = s[left];
                s_mat[leftchar]--;
                
                if(charFreq.count(leftchar) && s_mat[leftchar]<charFreq[leftchar]){
                    debt--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX?  "" :s.substr(newLeft,minLen);

    }
};
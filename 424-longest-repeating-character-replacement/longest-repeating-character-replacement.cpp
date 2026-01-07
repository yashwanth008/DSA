class Solution {
public:
    int characterReplacement(string s, int k) {
        int maps[26] = {0};
        int i = 0,j = 0;
        int maxFreq = 0;
        int maxLen = INT_MIN;
        while(j<s.size()){
            maps[s[j] - 'A']++;
            maxFreq = max(maxFreq,maps[s[j] - 'A']);
            // seeing if this exe
            if((j-i+1) - maxFreq > k){
                maps[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxFreq,(j-i+1));
            j++;
        }
        return maxLen;

    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1Freq,s2Freq;
        for(char c:s1) s1Freq[c]++;
        int l = 0,r = 0;
        while(r<s2.size()){
            char c = s2[r];
            s2Freq[c]++;
            if((r-l+1) > s1.size()){
                char leftChar = s2[l];
                s2Freq[leftChar]--;
                if(s2Freq[leftChar] == 0) s2Freq.erase(leftChar);
                l++;
            }
            if((r-l+1) == s1.size())
                if(s2Freq == s1Freq) return true;
            r++;
        }
        return false;
    }
};
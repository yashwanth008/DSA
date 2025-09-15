class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        array<int,26> need{};
        array<int,26> win{};
        if( k > s2.size()) return false;
        for(char c : s1) need[c - 'a']++;
        for(int i = 0;i < k;++i) win[s2[i] - 'a']++;
        if(win == need) return true;
        for(int i = k;i < s2.size();++i){
            win[s2[i] - 'a']++;
            win[s2[i-k] - 'a']--;
            if(win == need) return true;
        }
        return false;
    }
};
class Solution {
    bool boolCheck(const array<int,26>& a,const array<int,26>& b){
        for(int j = 0;j<26;++j) if(a[j] != b[j]) return false;
         return true;   
    }
public:
    vector<int> findAnagrams(string s, string p) {
       array<int,26> need{}; // map of p 
       array<int,26> window{}; // map of window
       int n = s.size();
       int k = p.size();
       if (k > n) return {}; // edge case of p is large than string it self

       //freq map for need
       for(char c: p) need[c - 'a']++;

       //fill up the first window 
       for (int i = 0;i < k;++i) window[s[i] - 'a']++;
       vector<int> result;
       //check for first window and add 0
       if(boolCheck(need,window)) result.push_back(0);

       for(int i = k;i < n; ++i){
        window[s[i] - 'a']++; // add the right element into the window 
        window[s[i-k] - 'a']--; // remove the left element of the window
        if(boolCheck(need,window)) result.push_back(i-k+1);
       }
    return result;
    }
};
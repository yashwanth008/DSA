class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int,int> freqMap;
        vector<int> res;
        int sz;
        for(int i = 0;i<n;i++){
            freqMap[candyType[i]]++;
        }
        for(auto &entry: freqMap){
            res.push_back(entry.first);
        }
        sz = res.size();
        return min(sz,n/2);
    }
};
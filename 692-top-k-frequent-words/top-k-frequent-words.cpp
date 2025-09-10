
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto i : words){
            freq[i]++;
        }
        vector<pair<string,int>> freqVec(freq.begin(),freq.end());
        sort(freqVec.begin(), freqVec.end(),
          [](const pair<string,int>& a,
             const pair<string,int>& b) {
                if(a.second == b.second){
                   return a.first < b.first;
                }
              return a.second > b.second;   // sort by value desc
          });
        vector<string> result;
        for(int i = 0;i < k; i++){
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};
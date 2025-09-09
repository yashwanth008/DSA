class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> result;
        for(int i = 0;i < nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> sortedFreq(freq.begin(),freq.end());
        sort(sortedFreq.begin(),sortedFreq.end(),[](auto &a,auto &b){
            return a.second > b.second; //ascending order
        });
        for(int i = 0; i < k && i < (int)sortedFreq.size();i++){
            result.push_back(sortedFreq[i].first);
            
        }
        return result;
    }
};
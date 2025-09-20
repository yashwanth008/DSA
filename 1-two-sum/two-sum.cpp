class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> posMap;
        for(int i =0;i<nums.size();i++){
            posMap[nums[i]] = i;
        }
        for(int i = 0;i < nums.size();i++){
            int comp = target - nums[i];
            if((posMap.find(comp) != posMap.end() &&  ( posMap[comp] != i))) return {i,posMap[comp]};
        }
        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numMap;
        for(int i = 0;i<nums.size();i++){
            numMap[nums[i]] = i;
        }
        
        for(int i = 0;i<nums.size();i++){
            int com = target - nums[i];
            if(numMap.count(com) && numMap[com] != i) return {i,numMap[com]};
        }
        return {};
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
            if(freq[i] > 1) return i;
        }
        return 0;
    }
};
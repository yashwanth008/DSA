class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> freq;
        int res = 0;
        for(int i:nums){
            freq[i]++;
            if(freq[i] > 1){
                
                res = i;
                break;
            }
        }
        return res;

    }
};
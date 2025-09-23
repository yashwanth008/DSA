class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(),nums.end());
        int longest = 0;
        for(int it: seq){
            if(seq.find(it-1) == seq.end()){
                int count = 1;
                while(seq.find(it+1) != seq.end()){
                    it += 1;
                    count++;
                }
                longest = max(longest,count);
            }
           
        }
        return longest;
    }
};
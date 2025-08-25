class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // fix the first element 
        for(int i = 0;i < n;i++){
            //if nums[i] > 0 then it can never add upto 0
            if( nums[i] > 0) break;
            // if nums[i] & nums[i-1] are same then skip cause we dont need duplicates
            if((i > 0) && (nums[i] == nums[i-1])) continue;
            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left]+ nums[right];
                // if sum > 0 decrease right && if sum < 0 increase left
                if(sum > 0)right--;
                else if(sum<0)left++;
                else{
                    vector<int> temp = {nums[i],nums[left],nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;
                    while((left < right) && (nums[left] == nums[left -1])){
                        left++;
                    }
                }
            }
        }
        return ans;
        
    }
};
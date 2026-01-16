class Solution {
public:
    
    // TLE
    // void largest(int l,int r,vector<int>& nums,int &mx){
    //     for(int i = l;i<=r;i++){
    //         mx = max(nums[i],mx);
    //     }
    //     result.push_back(mx);
    // }

  
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       //mono deq approach
       vector<int> result;
       deque<int>d;
       for(int i = 0;i < nums.size();i++){
         // decrease from front when window moves to next frame
         if(!d.empty() && d.front() == i - k) d.pop_front();
         // monotonic cond
         while(!d.empty() && nums[d.back()] < nums[i]) d.pop_back();
         // addin elms index condi
         d.push_back(i);
        // add the higest of window into result based on index
        if (i >= k - 1) result.push_back(nums[d.front()]);

       }
       return result;

       
    }
};
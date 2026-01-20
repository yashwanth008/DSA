class Solution {
public:
    int trap(vector<int>& height) {
        //monotonic stack approach
        //helps holding the prev greatest height
        stack<int> prevG;
        int ans = 0;
        for(int i = 0;i<height.size();i++){
            // if we find a greater element than current top then 
            while(!prevG.empty() && height[prevG.top()] < height[i]){
                int pop_height = height[prevG.top()];
                prevG.pop();
                // indicates its begining 
                if(prevG.empty()) break;
                // width ( next largest - prev largest - 1( to avoid both the walls))
                int distance = i - prevG.top() - 1;
                //height
                int water = min(height[prevG.top()],height[i]) - pop_height;
                ans+=(distance * water);
            }
            //add first element and add next prev best height and random pop heights
            prevG.push(i);
        }
        return ans;

    }
};
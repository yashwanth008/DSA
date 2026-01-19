class Solution {
public:
    int works(int mid,vector<int>&price,int k){
        int n = price.size();
        int prev = price[0];
        int count = 1;
        for(int i = 1;i<n;i++){
            if((price[i] - prev) >= mid){
                count++;
                prev = price[i];
            }
        }
        if(count >= k) return 1;
        return 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int low = 0;
        int high = price[n-1] - price[0];
        int result = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(works(mid,price,k)){
                result = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return result;
    }
};
int dp[101][27][101][101];
class Solution {
public:
    
    int solve(int idx,int last_char,int last_count,int k,string& s){
            int n = s.size();
            if(k < 0) return 1e9;
            if(idx == n) return 0;
            if (dp[idx][last_char][last_count][k] != -1) 
                return dp[idx][last_char][last_count][k];
            //option 1
            //delete;
            int res = solve(idx+1,last_char,last_count,k-1,s);
            //option 2
            //keep two ways -> 1, the idx is same as last char or 2. a new char
            if(s[idx] - 'a' == last_char){
                int inc = 0;
                if(last_count == 1 || last_count == 9 || last_count == 99){
                    inc = 1;
                }
                res = min(res, inc+solve(idx+1,last_char,last_count+1,k,s));

            }else{ 
                res = min(res,1+ solve(idx+1,s[idx] - 'a',1,k,s));
                
            }
            return dp[idx][last_char][last_count][k] = res;
        }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k, s);
        
    }
};
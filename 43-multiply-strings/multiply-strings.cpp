class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> sol(n1 + n2,0);
        string res = "";
        if( num1 == "0" || num2 == "0") return "0";

        for(int i = n1-1;i>=0;i--){
            for(int j = n2-1; j>=0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + sol[i+j+1];
                sol[i+j+1] = sum%10;
                sol[i+j] += sum/10;
            }
        }
        for(int x:sol){
            if(!(res.empty() && x == 0)){
                res.push_back(x + '0');
            }
        }
        return res;
    }
};
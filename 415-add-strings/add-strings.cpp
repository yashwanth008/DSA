class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int carry = 0;
        string res = "";

        while(n1>=0 || n2>=0 || carry){
            int sum = carry;
            if(n1>=0){
                sum+=(num1[n1] - '0');
                n1--;
            }
            if(n2>=0){
                sum+=(num2[n2] - '0');
                n2--;
            }
            carry = sum/10;
            res.push_back(sum%10 + '0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
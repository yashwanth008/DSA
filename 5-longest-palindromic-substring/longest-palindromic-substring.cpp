class Solution {
    private: int expandFromCentre(int left,int right,string& s){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()) return " ";
        int start = 0;
        int end = 0;
        for(int i = 0;i < s.length();i++){
            int odd = expandFromCentre(i,i,s);
            int even = expandFromCentre(i,i+1,s);
            int max_len = max(odd,even);
            if(max_len > end - start){
                start = i - (max_len - 1)/2;
                end = i + (max_len)/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
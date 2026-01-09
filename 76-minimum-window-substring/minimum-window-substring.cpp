class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> charFreq_t,charFreq_s;
        for(char c:t) charFreq_t[c]++;
        //operates window sizing
        int left = 0,right  = 0;
        int minLen = INT_MAX;
        // a counter to operate how many matched with t
        int present = 0;
        int req_total = t.size();
        
        // a temp left so get from substr
        int newLeft = 0;
        while(right < s.size()){
            char c = s[right];
            charFreq_s[c]++;
            if(charFreq_t.count(c) && charFreq_s[c] <= charFreq_t[c]) present++;

            // see if all the t chars are matched
            while(present == req_total){
                if((right - left + 1) < minLen){
                    minLen = right - left + 1;
                    newLeft = left;

                }
                char c_l = s[left];
                charFreq_s[c_l]--;
                // since when left reaches C at pos 5 it reduces to 0 so it will fail if condn 
                if(charFreq_t.count(c_l) && charFreq_s[c_l] < charFreq_t[c_l]) present--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(newLeft,minLen);
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
       //two pointers
       int i = 0,j = 0;
       // a array to understand freq of each character;
       int freq[26] = {0};
       // understanding charLen;
       int charLen = 0;
       //obv
       int maxLen = INT_MIN;
       while(j<s.size()){
        //freq of the char is counted
        freq[s[j] - 'A']++;
        // essentially picking max char len so that i can hold allways max char;
        charLen = max(charLen,freq[s[j] - 'A']);
        // now if k is exhausted and is exceeding you cant replace anymore
        // if exceeded then decrease the first char size ( replish one k) and inc i drc window
        if((j-i+1) - charLen > k){
            freq[s[i]-'A']--;
            i++;
        }
        maxLen = max(charLen,(j-i+1));
        j++;
       }
        return maxLen;
    }
};
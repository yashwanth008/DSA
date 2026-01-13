class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq;
        for(char c: magazine) freq[c]++;

        for(int i = 0;i<ransomNote.size();i++){
            char ch = ransomNote[i];
            if(freq.count(ch) && freq[ch] > 0){
                freq[ch]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
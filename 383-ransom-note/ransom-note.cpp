class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // sol 1
        // unordered_map<char,int>freq;
        // for(char c: magazine) freq[c]++;

        // for(int i = 0;i<ransomNote.size();i++){
        //     char ch = ransomNote[i];
        //     if(freq.count(ch) && freq[ch] > 0){
        //         freq[ch]--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;

        unordered_map<char,int> r,m;
        for(char c: ransomNote) r[c]++;
        for(char c: magazine) m[c]++;
        int i = 0;
        while(i < ransomNote.size()){
            if(m.count(ransomNote[i]) && m[ransomNote[i]] >= r[ransomNote[i]]){
                i++;
            }
            else return false;
        }
        return true;
    }
};
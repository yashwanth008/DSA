class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
       
        string comp = "";
        for(int i = 0;i<n;i++){
            char ch = word[i];
            int count = 1;
            while(i<n-1 && word[i] == word[i+1]){
                i++;
                count++;
            }
            while(count>9){
                    count = count-9;
                    comp += to_string(9) + string(1,ch);
            }
            comp += to_string(count) + string(1,ch);
        }
        return comp;
    }
};
//"9f9d16d4m9o1o2s" my
//"9f9d9d7d4m9o1o2s" exp
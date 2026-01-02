class Solution {
public:
    string getHint(string secret, string guess) {
        // methond 1 beats 28%

        // unordered_map<char,int> cowCount;
        // int x = 0,y = 0;
        // for(int i = 0;i<secret.size();i++){
        //     if(secret[i] == guess[i]) x++;
        //     else{
        //         cowCount[secret[i]]++;
        //         //cout<<cowCount[secret[i]]<<i<<" ";
        //     }
        // }
        // for(int j = 0;j<guess.size();j++){
        //     char ch = guess[j];
        //     if(cowCount.count(ch) && cowCount[ch] > 0 && secret[j] != ch){
        //         cowCount[ch]--;
        //         //cout<<cowCount[ch]<<ch<<" ";
        //         y++;
        //     }
        // }
        // return to_string(x) + "A" + to_string(y) + "B";

        //method 2 

        vector<int> sec(10);
        vector<int> gue(10);
        int x = 0,y = 0;
        for(int i = 0;i<secret.size();i++){
            if(secret[i] == guess[i]) x++;
            else{
                sec[secret[i] - '0']++;
                gue[guess[i] - '0']++;
            }
        }
        for(int j = 0;j<10;j++){
            y += min(gue[j],sec[j]);
        }
        return to_string(x) + "A" + to_string(y) + "B";

    }
};
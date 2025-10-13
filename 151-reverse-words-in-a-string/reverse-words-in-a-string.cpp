class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0,r = 0;
        reverse(s.begin(),s.end());
        while(i<n){
            //skip the empties
            while(i<n && s[i] == ' ') i++;

            //check if i reach end
            if(i == n) break;
            
            // if r>0 that implies there is a space
            if(r>0) s[r++] = ' ';
            // since now my i has reached to a word i will use this as begin and j as moving pointer
            int j = i;
            while(j < n && s[j] != ' ') j++;
            // now i know my word is from [i,j) 
            reverse(s.begin()+i,s.begin() + j);

            //get i and r to jth position since thats the current index
            while(i<j) s[r++] = s[i++];
        }
        s.resize(r);
        return s;
    }
};
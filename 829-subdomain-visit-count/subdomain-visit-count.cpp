class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> dmCount;
        for(auto dm:cpdomains){
            int idx = dm.find(" ");
            int num = stoi(dm.substr(0,idx));
            string s = dm.substr(idx+1);
            for(int i = 0;i<s.size();i++){
                if(s[i] == '.'){
                    dmCount[s.substr(i+1)] += num;
                }
            }
            dmCount[s] +=num;
        }
        vector<string> result;
        for(auto k:dmCount){
            result.push_back(to_string(k.second) + " " + k.first);
        }
        return result;
    }
};
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> subDomainCount;
        for(auto it:cpdomains){
            int i = it.find(" ");
            int num = stoi(it.substr(0,i));
            string s = it.substr(i+1);
            for(int i = 0;i<s.size();i++){
                if(s[i] == '.'){
                    subDomainCount[s.substr(i+1)] += num;
                }
            }
            subDomainCount[s]+=num;
            cout<<subDomainCount[s];   
        }
        vector<string>result;
        for(auto dm:subDomainCount){
            result.push_back(to_string(dm.second)+" "+dm.first);
        }
        return result;
    }
};
class Solution {
public:
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> unquie;  //checking uniqie domain and localname
        for(string &email:emails){
            int n = email.size();
            string cleanEmail = "";
            for(char &i:email){
                if(i == '+' || i == '@') break;
                if(i == '.') continue;
                cleanEmail+=i;
            }
            int pos = email.rfind('@');
            string domainName = email.substr(pos,n);
            cleanEmail+=domainName;
            if(!unquie.count(cleanEmail)) unquie[cleanEmail] = n;
            
        }
        return unquie.size();
    }
};
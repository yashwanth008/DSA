class Solution {
public:
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unquie;  //checking uniqie domain and localname
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
            cout<<cleanEmail;
            unquie.insert(cleanEmail);
            
        }
        return unquie.size();
    }
};
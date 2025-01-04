class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='(')balance++;
            else if(s[i]==')'){
                if(balance)balance--;
                else {
                    s[i]='*';
                }
            }
        }

        balance = 0;
        for(int i=(int)s.size()-1;i>=0;i--){
            if(s[i]==')')balance++;
            else if(s[i]=='('){
                if(balance)balance--;
                else{
                    s[i]='*';
                }
            }
        }

        string ans="";
        for(int i=0;i<s.size();i++)if(s[i]!='*')ans+=s[i];

        return ans;
    }
};

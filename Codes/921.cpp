class Solution {
public:
    // ((())
    int minAddToMakeValid(string s) {
        int ans = 0, balance = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')balance++;
            else {
                if(balance)balance--;
                else ans++;
            }
        }

        return ans+balance;
    }
};

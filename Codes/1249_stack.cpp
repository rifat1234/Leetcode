class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        unordered_set<int> remove_idx;

        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='(')stk.push(i);
            else if(s[i]==')'){
                if(!stk.empty())stk.pop();
                else{
                    remove_idx.insert(i);
                }
            }
        }

        while(!stk.empty()){
            remove_idx.insert(stk.top());
            stk.pop();
        }

        string ans = "";
        for(int i=0;i<(int)s.size();i++)if(!remove_idx.contains(i))ans+=s[i];

        return ans;
    }
};

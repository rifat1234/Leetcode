class Solution {
public:
// s = "leetcode", wordDict = ["leet","code"]
//s = "applepenapple", wordDict = ["apple","pen"]
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordst = unordered_set<string>(wordDict.begin(),wordDict.end());
        vector<bool>vis(s.size(),false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            
            string str = "";
            for(int i=idx;i<s.size();i++){
                str+=s[i];
                if(!vis[i+1] && wordst.contains(str)){
                    if(i==s.size()-1)return true;
                    vis[i+1] = true;
                    q.push(i+1);
                }
            }
        }
        
        return false;
    }
};

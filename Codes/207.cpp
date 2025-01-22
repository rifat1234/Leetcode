class Solution {
private:
    bool isCycle(int nd, vector<vector<int>> &g, vector<bool> &stk, vector<bool> &seen){
        if(stk[nd])return true;
        if(seen[nd])return false;
        stk[nd] = true;
        seen[nd] = true;
        bool ret = false;
        for(auto val: g[nd]){
            ret = ret || isCycle(val,g,stk,seen);
        }
        
        stk[nd] = false;
        return ret;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<bool> seen(numCourses, false);
        vector<bool> stk(numCourses, false);
        for(auto pre:prerequisites)g[pre[1]].push_back(pre[0]);
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,g,stk,seen))return false;
        }
        
        return true;
    }
};

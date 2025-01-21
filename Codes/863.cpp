/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> par;
    void addPar(TreeNode* nd, TreeNode* p){
        if(!nd)return;
        par[nd] = p;
        addPar(nd->left, nd);
        addPar(nd->right, nd);
    }
public:
//root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        addPar(root,nullptr);
        
        unordered_set<TreeNode*> seen; 
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(target,0));
        seen.insert(target);
        
        while(!q.empty()){
            auto nd = q.front().first;
            auto w = q.front().second;
            q.pop();
            
            
            if(!nd)continue;
            if(w==k){
                ans.push_back(nd->val);
                continue;
            }
            
            if(!seen.contains(nd->left)){
                q.push(make_pair(nd->left, w+1));
                seen.insert(nd->left);
            }
            
            if(!seen.contains(nd->right)){
                q.push(make_pair(nd->right, w+1));
                seen.insert(nd->right);
            }
            
            if(!seen.contains(par[nd])){
                q.push(make_pair(par[nd], w+1));
                seen.insert(par[nd]);
            }
        }
        
        return ans;
    }
};

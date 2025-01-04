/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;

        queue <pair<TreeNode*,int>> q;
        map<int,vector<int>>mp;

        q.push(make_pair(root,0));

        while(!q.empty()){
            auto nd = q.front().first;
            auto col = q.front().second;
            q.pop();
            if(!mp.count(col))mp[col]=vector<int>();
            mp[col].push_back(nd->val);

            if(nd->left!=nullptr){
                q.push(make_pair(nd->left, col-1));
            }

            if(nd->right!=nullptr){
                q.push(make_pair(nd->right, col+1));
            }
        }

       
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};

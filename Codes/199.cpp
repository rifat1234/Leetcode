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
    void f(TreeNode* nd, int depth, vector<int> &ans){
        if(nd==nullptr)return;
        if(ans.size()==depth)ans.push_back(nd->val);
        f(nd->right,depth+1,ans);
        f(nd->left,depth+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        f(root,0,ans);
        return ans;
    }
};

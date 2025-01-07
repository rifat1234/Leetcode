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
    pair<int,int> f(TreeNode* nd) {
        if(nd==nullptr)return make_pair(0,0);
        auto l = f(nd->left);
        auto r = f(nd->right);
        int d = max(l.first+r.first,max(l.second,r.second));
        int mx = max(l.first,r.first)+1;
        return make_pair(mx,d);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).second;
    }
};

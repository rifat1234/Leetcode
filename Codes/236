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
    TreeNode* lca;
public:
    int f(TreeNode* nd, TreeNode* p, TreeNode* q){
        if(nd==nullptr)return 0;
        
        int l = f(nd->left,p,q);
        int r = f(nd->right,p,q);
        int md = (nd==p || nd==q) ? 1:0;
        if(l+r+md == 2)lca = nd;
        return max(max(l,r),md);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f(root,p,q);
        return lca;
    }


};

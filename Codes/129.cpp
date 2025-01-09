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
    int sumNumbers(TreeNode* root) {
        return f(root,0);
    }
    
    int f(TreeNode* nd, int val){
        int newVal = val*10+nd->val;
        if(nd->left==nullptr && nd->right==nullptr)return newVal;
        int l = (nd->left!=nullptr) ? f(nd->left,newVal):0;
        int r = (nd->right!=nullptr) ? f(nd->right,newVal):0;
        
        return l+r;
        
    }
};

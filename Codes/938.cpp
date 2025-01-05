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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)return 0;
        int val = root->val;
        bool inRange = val>=low && val<=high;
        int l = low < val ? rangeSumBST(root->left, low, high): 0;
        int r = high > val ? rangeSumBST(root->right, low, high): 0;
        return l + r + (inRange ? val:0);
    }
};

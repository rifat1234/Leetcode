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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        
        while(root){
            double diff = fabs(target - double(root->val));
            double prevDiff = fabs(target - double(ans));
            if(diff < prevDiff || (ans > root->val && fabs(prevDiff-diff)< 0.0000001)) ans = root->val;
            
            if (diff < 0.00000001)root = root->left;
            else if(target<root->val)root=root->left;
            else root = root->right;
        }
        
        return ans;
    }
};

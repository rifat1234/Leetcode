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
 
 /*
    5
3       6
2 4    
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)return false;
        bool nullFound = false;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            auto nd = q.front();
            q.pop();

            if(nd==nullptr){
                nullFound = true;
                continue;
            }
            
            if(nullFound)return false;
            q.push(nd->left);
            q.push(nd->right);
        }
        
        return true;
    }
};

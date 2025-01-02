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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector< pair<pair<int,int>,int>>> mp;
        f(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            auto val = it->second;
            sort(val.begin(),val.end());
            vector<int> cur;
            for(int i=0;i<val.size();i++)cur.push_back(val[i].second);
            ans.push_back(cur);
        }

        return ans;
    }

    void f(TreeNode* root, int row, int col, map<int,vector<pair<pair<int,int>,int>>> &mp){
        if(root == nullptr)return;
        if(!mp.count(col))mp[col]=vector<pair<pair<int,int>,int>>();
        mp[col].push_back(make_pair(make_pair(row,col),root->val));
        f(root->left,row+1,col-1,mp);
        f(root->right,row+1,col+1,mp);
    }
};

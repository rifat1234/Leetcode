/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
    1
   2 3
 4 5 6 7
 // vis 1 2 4
*/

class Solution {
public:
    void f(Node *nd, int depth, vector<Node *> &vis){
        if(nd == nullptr)return;
        if(depth == vis.size()){
            vis.push_back(nd);
        } else {
            nd->next = vis[depth];
            vis[depth] = nd;
        }
        
        f(nd->right, depth+1, vis);
        f(nd->left, depth+1, vis);
    }
    Node* connect(Node* root) {
        vector<Node *> vis;
        f(root,0,vis);
        return root;
    }
};

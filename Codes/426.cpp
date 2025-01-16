/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        Node *l=nullptr, *r = nullptr;
        f(root,l,r);
        l->left = r;
        r->right = l;
        
        return l;
    }
    
    void f(Node* nd, Node* &l, Node* &r){
        if(nd == nullptr)return;
        f(nd->left,l,r);
        if(l == nullptr)l=nd;
        if(r){
            nd->left = r;
            r->right = nd;
        }
        r = nd;
        f(nd->right,l,r);
        
    }
};

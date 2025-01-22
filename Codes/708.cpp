/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        int cnt = 0;
        auto cur = head;
        while(cur){
            cnt++;
            cur=cur->next;
            if(cur==head)break;
        }
        //head = [3,4,1], insertVal = 2
        //head = [], insertVal = 1
        //head = [1], insertVal = 0
        auto nd = new Node(insertVal);
        if(!cnt){
            head = nd;
            nd->next = nd;
        }else if(cnt == 1){
            head->next = nd;
            nd->next = head;
        } else {
            Node *h=head,*t=head;
            cur = head;
            while(cur){
                if(cur->val >= t->val){
                    if(t->val == cur->val && cur->next->val < t->val)t=cur;
                    else if(cur->val > t->val)t=cur;
                }
                if(cur->val < h->val)h=cur;
                cur=cur->next;
                if(cur==head)break;
            }
            
            if(insertVal>t->val || insertVal<h->val){
                nd->next = t->next;
                t->next = nd;
            } else {
                while(h->next->val < insertVal){
                    h=h->next;
                }
                
                nd->next = h->next;
                h->next = nd;
            }
        }
        return head;
    }
};

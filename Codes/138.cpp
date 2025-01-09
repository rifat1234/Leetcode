/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node *oldHead = head;
        
        while(head){
            auto nd = new Node(head->val);
            mp[head] = nd;
            head = head->next;
        }
        
        head = oldHead;
        Node* newHead=nullptr;
        while(oldHead){
            newHead = mp[oldHead];
            if(oldHead->next)newHead->next = mp[oldHead->next];
            if(oldHead->random)newHead->random = mp[oldHead->random];
            oldHead = oldHead->next;          
        }
        
        return mp[head];
    }
};

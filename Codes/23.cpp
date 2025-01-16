/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        
        for(auto list:lists){
            if(list)q.push(list);
        }
        
        ListNode *head = nullptr, *cur = nullptr;
        while(!q.empty()){
            auto nd = q.top();
            q.pop();
            if(!cur){
                cur = nd;
                head = nd;
            } else{
                cur->next = nd;
                cur=cur->next;
            }
            
            if(nd->next)q.push(nd->next);
        }
        
        return head;
    }
};

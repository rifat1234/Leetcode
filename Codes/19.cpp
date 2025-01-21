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
    // head = [1,2,3,4,5], n = 2 , cnt = 5, target = 3
    // head = [1], n=1, cnt = 1, target = 0
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        auto cur = head;
        
        while(cur){
            if(!cur)break;
            cnt++;
            cur = cur->next;
        }
        
        int target = cnt - n;
        auto dummy = new ListNode(-1, head);
        cur = dummy;
        
        while(target > 0){
            target--;
            cur = cur->next;
        }
        
        if(cur->next)cur->next = cur->next->next;
        
        return dummy->next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        
        while(p != nullptr && p->next != nullptr)
        {
            int tmp = p->val;
            p->val = p->next->val;
            p->next->val = tmp;
            p = p->next->next;
        }
        
        return head;
    }
};
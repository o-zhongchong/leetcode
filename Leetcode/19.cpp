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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
        {
            return nullptr;
        }
        
        ListNode* pre = head;
        ListNode* cur = head;
        
        while(cur != nullptr && n--)
        {
            cur = cur->next;
        }
        
        if(cur == nullptr && n != 0)
        {
            return head;
        }
        
        if(cur == nullptr && n == 0)
        {
            return head->next;
        }
        
        while(cur->next != nullptr)
        {
            pre = pre->next;
            cur = cur->next;
        }
        
        pre->next = pre->next->next;
        return head;
    }
};
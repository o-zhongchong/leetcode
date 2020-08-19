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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k < 0)
        {
            return nullptr;
        }
        
        ListNode* p = head;
        int len = 1;
        
        while(p->next != nullptr)
        {
            p = p->next;
            ++len;
        }
        
        p->next = head;
        
        int i = len - k % len;
        ListNode* q = head;
        
        for(int j = 0; j < i; ++j)
        {
            p = q;
            q = q->next;
        }
        
        p->next = nullptr;
        return q;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( head == nullptr)
            return nullptr;
        
        ListNode* r = head;
        ListNode* p = head->next;
        r->next = nullptr;
        
        while( p != nullptr )
        {
            ListNode* node = p;
            p = p->next;
            node->next = nullptr;
            
            ListNode* pre = nullptr;
            ListNode* cur = r;
            
            while( cur !=nullptr && node->val >= cur->val )
            {
                pre = cur;
                cur = cur->next;
            }

            if( pre == nullptr)
            {
                node->next = cur;
                r = node;
            }
            else
            {
                node->next = pre->next;
                pre->next = node;
            }

        }
        
        return r;
    }
};

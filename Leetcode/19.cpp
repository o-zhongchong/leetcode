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
        
        int len = 1;
        ListNode* p = head;
        
        while(p->next != nullptr)
        {
            ++len;
            p = p->next;
        }
        
        if(n <= len)
        {
            ListNode* pre = nullptr;
            p = head;
            
            for(int i = 0; i < len - n; ++i)
            {
                pre = p;
                p = p->next;
            }
            
            if(pre != nullptr)
            {
                pre->next = p->next;
                delete p;
                return head;
            }
            else
            {
                pre = p->next;
                delete p;
                return pre;
            }
        }
        
        return nullptr;
    }
};
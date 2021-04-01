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
    int length(ListNode* head)
    {
        int len = 0;
        
        while(head != nullptr)
        {
            ++len;
            head = head->next;
        }
        
        return len;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* p = head;
        
        while(p != nullptr)
        {
            ListNode* t = p->next;
            p->next = pre;
            pre = p;
            p = t;
        }
        
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return true;
        }
        
        int len = length(head);
        ListNode* mid = head;
        
        for(int i=0; i<len/2; ++i)
        {
            mid = mid->next;
        }
        
        ListNode* tail = reverse(mid);
        ListNode* p1 = head;
        ListNode* p2 = tail;
        bool ret = true;
        
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1->val == p2->val)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                ret = false;
                break;
            }
        }
        
        reverse(tail);
        return ret;
    }
};
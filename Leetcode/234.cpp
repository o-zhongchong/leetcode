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
        ListNode* p = head;
        
        for(int i=0; i<len/2; ++i)
        {
            p = p->next;
        }
        
        ListNode* tail = reverse(p);
        ListNode* front = head;
        
        while(tail != nullptr && front != nullptr)
        {
            if(tail->val == front->val)
            {
                tail = tail->next;
                front = front->next;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};
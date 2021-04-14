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
    int append(ListNode* &head, ListNode* &tail, ListNode* &p)
    {
        if(head == nullptr && tail == nullptr)
        {
            head = tail = p;
            tail->next = nullptr;
        }
        else if(head != nullptr && tail != nullptr)
        {
            tail->next = p;
            tail = tail->next;
            tail->next = nullptr;
        }
        else
        {
            return -1;
        }
        
        return 0;
    }
    
    ListNode* merge(ListNode* &head1, ListNode* &tail1, ListNode* &head2, ListNode* &tail2)
    {
        if(head1 == nullptr)
        {
            return head2;
        }
        
        tail1->next = head2;
        return head1;
    }
    
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)
        {
            return nullptr;
        }
        
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        ListNode* tail1 = head1;
        ListNode* tail2 = head2;
        ListNode* p = head;
        
        while(p != nullptr)
        {
            ListNode* next = p->next;
            
            if(p->val < x)
            {
                append(head1, tail1, p);
            }
            else
            {
                append(head2, tail2, p);
            }
            
            p = next;
        }
        
        return merge(head1, tail1, head2, tail2);
    }
};
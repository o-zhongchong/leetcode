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
    
    ListNode* getNode(ListNode* head, int k)
    {
        ListNode* p = head;
        
        for(int i=1; i<k; ++i)
        {
            if(p != nullptr && p->next != nullptr)
            {
                p = p->next;
            }
            else
            {
                return nullptr;
            }
        }
        
        return p;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        
        if(k > len || head == nullptr)
        {
            return head;
        }
        
        ListNode* p1 = getNode(head, k);
        ListNode* p2 = getNode(head, len - k + 1);
        
        if(p1 != nullptr && p2 != nullptr)
        {
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
        
        return head;
    }
};
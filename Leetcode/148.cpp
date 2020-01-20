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
    ListNode* sortList(ListNode* head) {
        if( head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
protected:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        while( list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        
        if( list1 != nullptr)
            cur->next = list1;
        
        if( list2 != nullptr)
            cur->next = list2;
        
        cur = head->next;
        delete head;
        return cur;
    }
};
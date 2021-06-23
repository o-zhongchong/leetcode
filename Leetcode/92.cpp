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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* root = new ListNode();
        root->next = head;
        ListNode* pre = root;
        
        for(int i=0; i<left-1; ++i)
        {
            pre = pre->next;
        }
        
        ListNode* p = pre->next;
        
        for(int i=left; i<right; ++i)
        {
            ListNode* t = p->next;
            p->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        
        p = root->next;
        delete root;
        return p;
    }
};
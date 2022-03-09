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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode();
        root->next = head;
        ListNode *p=head, *pre=root;
        while(p) {
            bool flag = false;
            while(p->next && p->val == p->next->val) {
                flag = true;
                p->next = p->next->next;
            }
            if(flag) {
                pre->next = p->next;
            } else {
                pre = p;
            }
            p = p->next;
        }
        return root->next;
    }
};
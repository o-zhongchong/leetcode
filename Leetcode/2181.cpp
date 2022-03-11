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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *root = new ListNode();
        ListNode *p = head, *t = root;
        while(p) {
            if(p->val == 0) {
                p = p->next;
                continue;
            }
            if(p->next && p->next->val != 0) {
                p->val += p->next->val;
                p->next = p->next->next;
                continue;
            }
            t->next = p;
            p = p->next;
            t = t->next;
            t->next = nullptr;
        }
        return root->next;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode ret;
        ListNode *p = &ret;
        while(head) {
            if(head->val != val) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
            p->next = nullptr;
        }
        return ret.next;
    }
};
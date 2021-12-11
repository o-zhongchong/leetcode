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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode *p1, *p2;
        p1 = odd;
        p2 = even;
        int cnt = 1;
        while(head) {
            ListNode* t = head;
            head = head->next;
            t->next = nullptr;
            if(cnt & 1) {
                p1->next = t;
                p1 = p1->next;
            }
            else {
                p2->next = t;
                p2 = p2->next;
            }
            ++cnt;
        }
        if(!odd->next) {
            return even->next;
        }
        p1->next = even->next;
        return odd->next;
    }
};
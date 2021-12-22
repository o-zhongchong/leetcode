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
    void reorderList(ListNode* head) {
        int len = getLength(head);
        ListNode* p = head;
        for(int i=0; i<len/2-1; ++i) {
            p = p->next;
        }
        ListNode* L1 = head;
        ListNode* L2 = p->next; p->next=nullptr;
        L2 = reverse(L2);
        ListNode ret; p = &ret;
        while(L1 || L2) {
            if(L1) {
                p->next = L1;
                p = p->next;
                L1 = L1->next;
            }
            if(L2) {
                p->next = L2;
                p = p->next;
                L2 = L2->next;
            }
        }
    }
private:
    int getLength(ListNode* head) {
        int len = 0;
        while(head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode* reverse(ListNode* root) {
        ListNode* pre = nullptr;
        while(root) {
            ListNode* t = root->next;
            root->next = pre;
            pre = root;
            root = t;
        }
        return pre;
    }
};
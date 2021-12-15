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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* root = new ListNode();
        while(head) {
            ListNode* t = head->next;
            insert(root, head);
            head = t;
        }
        return root->next;
    }
private:
    void insert(ListNode* root, ListNode* n) {
        while(root->next && root->next->val <= n->val) {
            root = root->next;
        }
        n->next = root->next;
        root->next = n;
    }
};
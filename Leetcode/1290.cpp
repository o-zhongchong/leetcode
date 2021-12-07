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
    int getDecimalValue(ListNode* head) {
        int len = getLength(head);
        int ret = 0;
        while(head) {
            if(head->val) {
                ret += 1 << (len - 1);
            }
            head = head->next;
            --len;
        }
        return ret;
    }
private:
    int getLength(ListNode* root) {
        int ret = 0;
        while(root) {
            ++ret;
            root = root->next;
        }
        return ret;
    }
};
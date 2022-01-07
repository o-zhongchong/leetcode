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
    Solution(ListNode* head) {
        mHead = head;
        mLength = 0;
        while(head) {
            ++mLength;
            head = head->next;
        }
    }
    int getRandom() {
        int pos = rand() % mLength;
        ListNode* p = mHead;
        for(int i=0; i<pos; ++i) {
            p = p->next;
        }
        return p->val;
    }
private:
    int mLength;
    ListNode* mHead;
};

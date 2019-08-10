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
    ListNode* middleNode(ListNode* head) {
        int len = 0;

        ListNode* p = head;
        while( p!=nullptr )
        {
            ++len;
            p = p->next;
        }
        
        if( len == 0)
            return nullptr;
      
        if( len & 1)
            len = (len+1)/2;
        else
            len = len/2 + 1;
        
        --len;
        p = head;
        while(len--)
            p = p->next;
        return p;
    }
};
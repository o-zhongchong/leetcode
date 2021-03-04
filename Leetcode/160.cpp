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
    int getLength(ListNode* root)
    {
        int len = 0;
        
        while(root != nullptr)
        {
            ++len;
            root = root->next;
        }
        
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        if(len1 > len2)
        {
            for(int i=0; i<(len1 - len2); ++i)
            {
                p1 = p1->next;
            }
        }
        else if(len2 > len1)
        {
            for(int i=0; i<(len2 - len1); ++i)
            {
                p2 = p2->next;
            }
        }
        
        while(p1 != nullptr && p1 != nullptr && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1 != nullptr ? p1 : nullptr;
    }
};
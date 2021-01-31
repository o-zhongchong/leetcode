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

struct cmp
{
    bool operator()(const ListNode* a, const ListNode* b) const
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* front = nullptr;
        ListNode* tail = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        int len = lists.size();
        
        for(int i=0; i<len; ++i)
        {
            if(lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty())
        {
            ListNode* p = pq.top();
            pq.pop();
            
            if(p->next != nullptr)
            {
                pq.push(p->next);
            }
            
            if(front == nullptr)
            {
                front = new ListNode(p->val);
                tail = front;
            }
            else
            {
                tail->next = new ListNode(p->val);
                tail = tail->next;
            }
        }
        
        return front;
    }
};
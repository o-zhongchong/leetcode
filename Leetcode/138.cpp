/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* ret = new Node(head->val);
        Node* p1 = ret;
        Node* p2 = head;
        int i = 0;
        unordered_map<Node*,int> addr_i;
        unordered_map<int, Node*> i_addr;
        addr_i.insert(make_pair(head, i));
        i_addr.insert(make_pair(i, ret));
        
        while(p2->next != nullptr)
        {
            p1->next = new Node(p2->next->val);
            addr_i.insert(make_pair(p2->next, i + 1));
            i_addr.insert(make_pair(i + 1, p1->next));
            p2 = p2->next;
            p1 = p1->next;
            ++i;
        }
        
        p1 = ret;
        p2 = head;
        
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p2->random == nullptr)
            {
                p1->random = nullptr;
            }
            else
            {
                i = addr_i[p2->random];
                Node* r = i_addr[i];
                p1->random = r;
            }
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return ret;
    }
};
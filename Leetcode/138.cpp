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
        unordered_map<Node*,Node*> m;
        Node *p = head;
        while(p) {
            Node *n, *r;
            n = r = nullptr;
            if(!m.count(p)) 
                m[p] = new Node(p->val);
            if(p->next) {
                if(!m.count(p->next))
                    m[p->next] = new Node(p->next->val);
                n = m[p->next];
            }
            if(p->random) {
                if(!m.count(p->random))
                    m[p->random] = new Node(p->random->val);
                r = m[p->random];
            }
            m[p]->next = n;
            m[p]->random = r;
            p = p->next;
        }
        return m[head];
    }
};
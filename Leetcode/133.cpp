/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> m;
        queue<Node*> q; 
        Node* clone = new Node(node->val);
        m[node] = clone;
        q.push(node);
        while(!q.empty()) {
            Node* t = q.front(); q.pop();
            for(auto p : t->neighbors) {
                if(!m.count(p)) {
                    m[p] = new Node(p->val);
                    q.push(p);
                }
                m[t]->neighbors.push_back(m[p]);
            }
        }
        return clone;
    }
};
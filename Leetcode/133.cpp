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
        unordered_map<int, Node*> m;
        unordered_set<int> visited;
        queue<Node*> q; 
        q.push(node); visited.insert(node->val);
        while(!q.empty()) {
            Node* t = q.front(); q.pop();
            if(!m.count(t->val)) {
                m[t->val] = new Node(t->val);
            }
            for(auto p:t->neighbors) {
                if(!visited.count(p->val)) {
                    q.push(p);
                    visited.insert(p->val);
                }
                if(!m.count(p->val)) {
                    m[p->val] = new Node(p->val);
                }
                m[t->val]->neighbors.push_back(m[p->val]);
            }
        }
        return m[1];
    }
};
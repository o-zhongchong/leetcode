/* class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
}; */

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            Node* pre = nullptr;
            for (int i=0; i<sz; ++i) {
                Node* t = q.front(); q.pop();
                t->next = nullptr;
                if (pre != nullptr) pre->next = t;
                pre = t;
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
        }
        return root;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        postorder_traversal(root, ret);
        return ret;
    }
private:
    int postorder_traversal(Node* root, vector<int> &ret)
    {
        if( root == nullptr)
            return -1;

        for( auto i: root->children )
            postorder_traversal(i, ret);
        ret.push_back(root->val);
        
        return 0;
    }
};
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        preorder_traversal(root, ret);
        return ret;
    }
private:
    int preorder_traversal(Node* root, vector<int> &ret)
    {
        if( root == nullptr)
            return -1;
        
        ret.push_back(root->val);
        for( auto i: root->children )
            preorder_traversal(i, ret);
        
        return 0;
    }
};
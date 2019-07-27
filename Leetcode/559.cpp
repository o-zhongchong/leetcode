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
    int maxDepth(Node* root) {
        int max = 0;
        findDepth(root, max, 1);
        return max;
    }
private:
    int findDepth(Node* root, int &max, int cur)
    {
        if( root == nullptr)
            return 0;
        if( cur > max )
            max = cur;
        for( auto &i : root->children)
            findDepth(i, max, cur+1);
        return 0;
    }
};
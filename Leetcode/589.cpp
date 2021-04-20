/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* root, vector<int> &ret)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        ret.push_back(root->val);
        
        for(Node* p : root->children)
        {
            if(p != nullptr)
            {
                dfs(p, ret);
            }
        }
        
        return 0;
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
};
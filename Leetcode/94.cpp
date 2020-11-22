/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) 
 *             : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        
        TreeNode* p = root;
        stack<TreeNode*> st;
        vector<int> ret;
        
        while(p != nullptr || !st.empty())
        {
            while(p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            
            p = st.top();
            ret.push_back(p->val);
            st.pop();
            p = p->right;
        }
        
        return ret;
    }
};
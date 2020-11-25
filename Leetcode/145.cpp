/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        
        list<int> ret;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* p = st.top();
            ret.push_front(p->val);
            st.pop();
            
            if(p->left != nullptr)
            {
                st.push(p->left);
            }
            
            if(p->right != nullptr)
            {
                st.push(p->right);
            }
        }
        
        vector<int> r;
        
        for(int i : ret)
        {
            r.push_back(i);
        }
        
        return r;
    }
};
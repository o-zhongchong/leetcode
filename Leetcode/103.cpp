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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        
        stack<TreeNode*> st1, st2;
        vector<vector<int>> ret;
        st1.push(root);
        
        while(!st1.empty() )
        {
            vector<int> tmp;
            
            while(!st1.empty())
            {
                TreeNode* p = st1.top();
                
                if(p->left != nullptr)
                {
                    st2.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    st2.push(p->right);
                }
                
                tmp.push_back(p->val);
                st1.pop();
            }
            
            if(!tmp.empty())
            {
                ret.push_back(tmp);
            }
            
            tmp.clear();
            
            while(!st2.empty())
            {
                TreeNode* p = st2.top();
                
                if(p->right != nullptr)
                {
                    st1.push(p->right);
                }
                
                if(p->left != nullptr)
                {
                    st1.push(p->left);
                }
                
                tmp.push_back(p->val);
                st2.pop();
            }
            
            if(!tmp.empty())
            {
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
};
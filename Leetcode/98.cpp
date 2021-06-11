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
    bool helper(TreeNode* root, pair<int,int> &ret)
    {
        if(root == nullptr)
        {
            return true;
        }
        
        pair<int,int> ret1, ret2;
        
        if(root->left != nullptr)
        {
            if(!helper(root->left, ret1) || ret1.second >= root->val)
            {
                return false;
            }
            
            ret.first = ret1.first;
        }
        else
        {
            ret.first = root->val;
        }
        
        if(root->right != nullptr)
        {
            if(!helper(root->right, ret2) || ret2.first <= root->val)
            {
                return false;
            }
            
            ret.second = ret2.second;
        }
        else
        {
            ret.second = root->val;
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        pair<int,int> ret;
        return helper(root, ret);
    }
};
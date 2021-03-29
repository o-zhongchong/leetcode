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
    bool helper(TreeNode* root, vector<int>& voyage, int &i, vector<int> &ret)
    {
        if(root == nullptr)
        {
            return true;
        }
        
        if(root->val != voyage[i++])
        {
            return false;
        }
        
        if(root->left != nullptr && root->left->val != voyage[i])
        {
            ret.push_back(root->val);
            return helper(root->right, voyage, i, ret) && helper(root->left, voyage, i, ret);
        }
        
        return helper(root->left, voyage, i, ret) && helper(root->right, voyage, i, ret);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ret;
        int i=0;
        return helper(root, voyage, i, ret) ? ret : vector<int>{-1};
    }
};
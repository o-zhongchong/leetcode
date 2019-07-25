/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr )
            return false;
        
        bool ret;
        ret = check(root, root->val);
        
        return ret;
    }
private:
    bool check(TreeNode* root, int val)
    {
        if(root == nullptr)
            return true;
        
        if(root->val != val)
            return false;
        
        if( !check(root->left,val) )
            return false;
        
        if( !check(root->right,val) )
            return false;
        
        return true;
    }
};
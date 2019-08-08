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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> tree_stack;
        TreeNode* ret = nullptr;

        if( root == nullptr )
            return ret;
        else
            tree_stack.push(root);
        
        TreeNode* pre = nullptr;
        while( !tree_stack.empty() )
        {
            TreeNode* top = tree_stack.top();
  
            if( top->left != nullptr )
            {
                tree_stack.push(top->left);
                top->left = nullptr;
                continue;
            }

            tree_stack.pop();

            if( pre == nullptr )
            {
                ret = top;
            }
            else
                pre->right = top;

            if( top->right != nullptr )
            {
                tree_stack.push(top->right);
                top->right = nullptr;
            }
            pre = top;
        }
        return ret;
    }
};
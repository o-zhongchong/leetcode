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
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int ret = 0;
        getSum(root, root->val, ret);
        return ret;
    }

    int getSum(TreeNode* root, int num, int &ret)
    {
        if(root->left == nullptr && root->right ==nullptr)
            ret += num;
        
        if(root->left != nullptr)
            getSum(root->left, num*2 + root->left->val, ret);
        
        if(root->right != nullptr)
            getSum(root->right, num*2 + root->right->val, ret);

        return 0;
    }
};
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
    int sumRootToLeaf(TreeNode* root) {
        int ret = 0;
        helper(root, 0, ret);
        return ret;
    }
private:
    void helper(TreeNode* root, int sum, int &ret) {
        if(root == nullptr) return;
        sum = (sum << 1) + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            ret += sum;
            return;
        }
        if(root->left != nullptr) helper(root->left, sum, ret);
        if(root->right != nullptr) helper(root->right, sum, ret);
    }
};
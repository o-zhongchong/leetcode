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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        needCoins(root, ret);
        return ret;
    }
private:
    int needCoins(TreeNode* root, int &count)
    {
        if (root == nullptr)
            return 0;

        int left = needCoins(root->left, count);
        int right = needCoins(root->right, count);

        int ret = 1 - root->val + left + right;
        count = count + abs(ret);

        return ret;
    }
};
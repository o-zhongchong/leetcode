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
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int ret = 0;
        helper(root, root->val, root->val, ret);
        return ret;
    }
private:
    void helper(TreeNode* root, int mx, int mn, int &res) {
        if(root == nullptr) return;
        res = max(res, abs(mx - root->val));
        res = max(res, abs(mn - root->val));
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        helper(root->left, mx, mn, res);
        helper(root->right, mx, mn, res);
    }
};
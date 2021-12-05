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
    int rob(TreeNode* root) {
        int dp1=0, dp2=0;
        helper(root, dp1, dp2);
        return max(dp1, dp2);
    }
private:
    void helper(TreeNode* root, int &dp1, int &dp2) {
        if(!root) {
            return;
        }
        int dp[4] = {0, 0, 0, 0};
        helper(root->left, dp[0], dp[1]);
        helper(root->right, dp[2], dp[3]);
        dp1 = root->val + dp[1] + dp[3];
        dp2 = max(dp[0], dp[1]) + max(dp[2], dp[3]);
    }
};
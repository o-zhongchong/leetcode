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
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }
private:
    int helper(TreeNode* root, int &sum) {
        if(root == nullptr) return 0;
        int L = helper(root->left, sum);
        int R = helper(root->right, sum);
        sum += abs(L - R);
        return L + R + root->val;
    }
};
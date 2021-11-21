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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size();
        return helper(inorder, 0, inorder.size(), postorder, pos);
    }
private:
    TreeNode* helper(vector<int>& inorder, int left, int right, vector<int>& postorder, int &pos) {
        if(pos <= 0 || left >= right) return nullptr;
        TreeNode* r = new TreeNode(postorder[--pos]);
        int idx = find(inorder, left, right, r->val);
        if(idx != -1) {
            r->right = helper(inorder, idx+1, right, postorder, pos);
            r->left = helper(inorder, left, idx, postorder, pos);
        }
        return r;
    }
    int find(vector<int> &nums, int left, int right, int target) {
        for(int i=left; i<right; ++i) {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};
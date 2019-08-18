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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ret;
        int height;
        getLCA(root, ret, height);
        return ret;
    }
protected:
    int getLCA(TreeNode* root, TreeNode* &ret, int &h)
    {
        if (root == nullptr)
        {
            ret = nullptr;
            h = 0;
            return 0;
        }
        
        TreeNode *r_left, *r_right;
        int h_left, h_right;

        getLCA(root->left, r_left, h_left);
        getLCA(root->right, r_right, h_right);

        if (h_left == h_right)
        {
            ret = root;
            h = h_left + 1;
        }
        else if (h_left > h_right)
        {
            ret = r_left;
            h = h_left + 1;
        }
        else
        {
            ret = r_right;
            h = h_right + 1;
        }

        return 0;
    }
};
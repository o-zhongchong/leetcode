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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int left1, int right1,
                       vector<int>& inorder, int left2, int right2)
    {
        if(left1 > right1 || left2 > right2)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[left1]);
        int pos = left2;
        
        while(pos <= right2 && preorder[left1] != inorder[pos])
        {
            ++pos;
        }
        
        root->left = buildTree(preorder, left1+1, pos-left2+left1,
                               inorder, left2, pos-1);
        root->right = buildTree(preorder, left1+1+pos-left2, right1,
                                inorder, pos+1, right2);
        return root;
    }
};
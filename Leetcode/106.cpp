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
        return buildTree(inorder, 0, inorder.size()-1,
                  postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int left1, int right1,
                        vector<int>& postorder, int left2, int right2)
    {
        if(left1 > right1 || left2 > right2)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[right2]);
        int pos = left1;
        
        while(pos <= right1 && inorder[pos] != postorder[right2])
        {
            ++pos;
        }
        
        root->left = buildTree(inorder, left1, pos-1,
                               postorder, left2, left2+pos-left1-1);
        root->right = buildTree(inorder, pos+1, right1,
                                postorder, left2+pos-left1, right2-1);
        return root;
    }
};
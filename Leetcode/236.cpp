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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, int &flag1, int &flag2)
    {
        if(root == nullptr){
            return nullptr;
        }
        
        int flag3, flag4, flag5, flag6;
        flag3 = flag4 = flag5 = flag6 = 0;
        
        TreeNode* left = helper(root->left, p, q, flag3, flag4);
        
        if(left != nullptr){
            return left;
        }
        
        TreeNode* right = helper(root->right, p, q, flag5, flag6);
        
        if(right != nullptr){
            return right;
        }
        
        flag1 = max(flag3, flag5);
        flag2 = max(flag4, flag6);
        
        if(root->val == p->val){
            flag1 = 1;
        }
        
        if(root->val == q->val)
        {
            flag2 = 1;
        }
        
        if(flag1 && flag2){
            return root;
        }
        
        return nullptr;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left, right;
        left = right = 0;
        return helper(root, p, q, left, right);
    }
};
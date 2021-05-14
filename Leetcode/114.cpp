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
    TreeNode* helper(TreeNode* head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        
        TreeNode* L = helper(head->left);
        TreeNode* R = helper(head->right);
        TreeNode* p = L;
        
        while(p != nullptr && p->right != nullptr)
        {
            p = p->right;
        }
        
        if(L != nullptr)
        {
            head->left = nullptr;
            p->right = R;
            head->right = L;
            return head;
        }
        
        head->left = nullptr;
        head->right = R;
        return head;
    }
    
    void flatten(TreeNode* root) {
        helper(root);
        return;
    }
};
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
    int get(TreeNode* root)
    {
        return root == nullptr ? 0 : root->val;
    }
    
    int dfs(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else if(root != nullptr && root->left == nullptr && root->right == nullptr)
        {
            root->val = 1;
            return 0;
        }
        
        dfs(root->left);
        dfs(root->right);
        
        root->val = INT_MAX;
        
        TreeNode* L = root->left;
        TreeNode* LL = (L == nullptr ? nullptr : L->left);
        TreeNode* LLL = (LL == nullptr ? nullptr : LL->left);
        TreeNode* LLR = (LL == nullptr ? nullptr : LL->right);
        TreeNode* LR = (L == nullptr ? nullptr : L->right);
        TreeNode* LRL = (LR == nullptr ? nullptr : LR->left);
        TreeNode* LRR = (LR == nullptr ? nullptr : LR->right);
        
        TreeNode* R = root->right;
        TreeNode* RL = (R == nullptr ? nullptr : R->left);
        TreeNode* RLL = (RL == nullptr ? nullptr : RL->left);
        TreeNode* RLR = (RL == nullptr ? nullptr : RL->right);
        TreeNode* RR = (R == nullptr ? nullptr : R->right);
        TreeNode* RRL = (RR == nullptr ? nullptr : RR->left);
        TreeNode* RRR = (RR == nullptr ? nullptr : RR->right);
        
        int s1 = min(get(L), get(LL) + get(LR)) + min(get(R), get(RL) + get(RR));
        root->val = min(root->val, s1 + 1);
        
        int s2 = min(get(LL), get(LLL) + get(LLR)) + min(get(LR), get(LRL) + get(LRR)) + 1;
        root->val = min(root->val, s2 + get(R));
        
        int s3 = min(get(RL), get(RLL) + get(RLR)) + min(get(RR), get(RRL) + get(RRR)) + 1;
        root->val = min(root->val, s3 + get(L));
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        
        dfs(root);
        return root->val;
    }
};
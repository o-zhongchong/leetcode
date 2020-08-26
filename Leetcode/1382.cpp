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
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
        
        vector<int> nums;
        inOrderTraversal(root, nums);
        TreeNode* r = buildTree(nums, 0, nums.size() - 1);
        
        return r;
    }
    
    TreeNode* buildTree(vector<int>& nums, int start, int end)
    {
        int len = nums.size();
        
        if( !(start >=0 && start <= end && end < len) )
        {
            return nullptr;
        }
        
        int mid = start + (end - start)/2;
        TreeNode* r = nullptr;
        
        if(mid >= 0 && mid < len)
        {
            r = new TreeNode(nums[mid]);
            r->left = buildTree(nums, start, mid - 1);
            r->right = buildTree(nums, mid + 1, end);
        }
        
        return r;
    }
    
    int inOrderTraversal(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        inOrderTraversal(root->left, nums);
        nums.push_back(root->val);
        inOrderTraversal(root->right, nums);
        return 0;
    }
};
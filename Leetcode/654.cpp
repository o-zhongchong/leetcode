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
    TreeNode* genRoot(vector<int>& num, int start, int end)
    {
        if(start > end)
            return nullptr;

        int maxPos = start;
        int maxVal = num[start];

        for(int i=start; i<=end; ++i)
        {
            if(num[i] > maxVal)
            {
                maxVal = num[i];
                maxPos = i;
            }
        }

        TreeNode* root = new TreeNode(maxVal);
        root->left = genRoot(num, start, maxPos-1);
        root->right = genRoot(num, maxPos+1, end);
        return root;
    };

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return genRoot(nums, 0, nums.size()-1);
    }
};

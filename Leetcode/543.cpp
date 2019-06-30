#include <algorithm>

class Solution {
public:    
    int diameter(TreeNode* node, int &partLen, int &maxLen)
    {
        int leftPartLen, leftMaxLen;
        int rightPartLen, rightMaxLen;
        
        if(node == nullptr)
        {
            partLen = 0;
            maxLen = 0;
            return -1;
        }
        else if(node->left == nullptr && node->right == nullptr)
        {
            partLen = 0;
            maxLen = 0;
            return 0;
        }
        else if(node->left == nullptr && node->right != nullptr)
        {
            diameter(node->right, rightPartLen, rightMaxLen);
            partLen = rightPartLen + 1;
            maxLen = max(partLen, rightMaxLen);
            return 0;
        }
        else if(node->left != nullptr && node->right == nullptr)
        {
            diameter(node->left, leftPartLen, leftMaxLen);
            partLen = leftPartLen + 1;
            maxLen = max(partLen, leftMaxLen);
            return 0;
        }
        else
        {
            diameter(node->right, rightPartLen, rightMaxLen);
            diameter(node->left, leftPartLen, leftMaxLen);
            partLen = max(leftPartLen, rightPartLen) + 1;
            maxLen = max(rightMaxLen, leftMaxLen);
            maxLen = max(maxLen, leftPartLen + rightPartLen + 2);
            return 0;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int partLen, maxLen;
        diameter(root, partLen, maxLen);
        return maxLen;
    }
};
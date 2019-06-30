//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode *preNode=nullptr;
        postOrderTraversal(root, preNode);
        return root;
    }

    int postOrderTraversal(TreeNode* root, TreeNode* &preNode)
    {
        if (root == nullptr)
            return -1;
        
        if ( root->right != nullptr)
            postOrderTraversal(root->right, preNode);

        if (preNode != nullptr)
            root->val += preNode->val;
         preNode = root;

         if (root->left != nullptr)
             postOrderTraversal(root->left, preNode);

         return 0;
    }
};
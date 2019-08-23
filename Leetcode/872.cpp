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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lef1, lef2;
        getLeaves(root1,lef1);
        getLeaves(root2,lef2);
        
        int len1 = lef1.size();
        int len2 = lef2.size();
        
        if( len1 != len2 )
            return false;
        for(int i=0; i<len1; ++i)
            if(lef1[i] != lef2[i])
                return false;
        return true;
    }
protected:
    int getLeaves(TreeNode* root, vector<int> &ret)
    {
        if(root == nullptr)
            return 0;
        
        if( root->left == nullptr && root->right == nullptr)
            ret.push_back(root->val);
        
        getLeaves(root->left,ret);
        getLeaves(root->right,ret);
        
        return 0;
    }
};
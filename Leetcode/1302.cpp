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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        
        int ret = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sum = 0;
            queue<TreeNode*> tmp;
            
            while(!q.empty())
            {
                TreeNode* p = q.front();
                q.pop();
                sum += p->val;
                
                if(p->left != nullptr)
                {
                    tmp.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    tmp.push(p->right);
                }
            }
            
            ret = sum;
            q = tmp;
        }
        
        return ret;
    }
};
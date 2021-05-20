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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> arr;
            queue<TreeNode*> tmp;
            
            while(!q.empty())
            {
                TreeNode* p = q.front();
                q.pop();
                arr.push_back(p->val);
                
                if(p->left != nullptr)
                {
                    tmp.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    tmp.push(p->right);
                }
            }
            
            ret.push_back(arr);
            q = tmp;
        }
        
        return ret;
    }
};
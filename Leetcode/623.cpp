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
    vector<TreeNode*> getNode(TreeNode* root, int d)
    {
        if(root == nullptr || d < 1)
        {
            return {};
        }
        
        queue<TreeNode*> q1;
        q1.push(root);
        
        for(int i=1; i<d; ++i)
        {
            queue<TreeNode*> q2;
            
            while(!q1.empty())
            {
                TreeNode* p = q1.front();
                q1.pop();
                
                if(p->left != nullptr)
                {
                    q2.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    q2.push(p->right);
                }
            }
            
            q1 = q2;
        }
        
        vector<TreeNode*> ret;
        
        while(!q1.empty())
        {
            ret.push_back(q1.front());
            q1.pop();
        }
        
        return ret;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* p = new TreeNode(v);
            p->left = root;
            return p;
        }
        
        vector<TreeNode*> nodes = getNode(root, d-1);
        
        for(auto &n: nodes)
        {
            TreeNode* p1 = new TreeNode(v);
            TreeNode* p2 = new TreeNode(v);
            
            p1->left = n->left;
            n->left = p1;
            p2->right = n->right;
            n->right = p2;
        }
        
        return root;
    }
};
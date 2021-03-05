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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        
        vector<double> ret;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        
        while(!q1.empty() || !q2.empty())
        {
            long long sum = 0, cnt = 0;
            
            while(!q1.empty())
            {
                TreeNode* p = q1.front();
                q1.pop();
                sum += p->val;
                ++cnt;
                
                if(p->left != nullptr)
                {
                    q2.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    q2.push(p->right);
                }
            }
            
            if(cnt > 0)
            {
                ret.push_back((double)(sum)/(double)(cnt));
                sum = 0;
                cnt = 0;
            }
            
            while(!q2.empty())
            {
                TreeNode* p = q2.front();
                q2.pop();
                sum += p->val;
                ++cnt;
                
                if(p->left != nullptr)
                {
                    q1.push(p->left);
                }
                
                if(p->right != nullptr)
                {
                    q1.push(p->right);
                }
            }
            
            if(cnt > 0)
            {
                ret.push_back((double)(sum)/(double)(cnt));
                sum = 0;
                cnt = 0;
            }
        }
        
        return ret;
    }
};
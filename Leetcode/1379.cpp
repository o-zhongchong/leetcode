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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, 
        TreeNode* target) 
    {
        queue<TreeNode*> q1, q2;
        q1.push(original);
        q2.push(cloned);
        while (q1.size() == q2.size() && !q1.empty()) {
            int len = q1.size();
            for (int i=0; i<len; ++i) {
                auto p1 = q1.front(); q1.pop();
                auto p2 = q2.front(); q2.pop();
                if (p1 == target) return p2;
                if (p1->left != nullptr) q1.push(p1->left);
                if (p1->right != nullptr) q1.push(p1->right);
                if (p2->left != nullptr) q2.push(p2->left);
                if (p2->right != nullptr) q2.push(p2->right);
            }
        }
        return nullptr;
    }
};
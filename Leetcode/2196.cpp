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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int len = descriptions.size();
        unordered_map<int,TreeNode*> m;
        unordered_map<int,bool> root;
        for(int i=0; i<len; ++i) {
            root[descriptions[i][0]] = true;
        }
        for(int i=0; i<len; ++i) {
            TreeNode *parent, *child;
            if(!m.count(descriptions[i][0])) {
                parent = new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]] = parent;
            } else {
                parent = m[descriptions[i][0]];
            }
            if(!m.count(descriptions[i][1])) {
                child = new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]] = child;
            } else {
                child = m[descriptions[i][1]];
            }
            root[descriptions[i][1]] = false;
            if(descriptions[i][2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        for(auto node : root) {
            if(node.second) return m[node.first];
        }
        return nullptr;
    }
};
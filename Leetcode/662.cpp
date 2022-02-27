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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, uint64_t>> q;
        q.push(make_pair(root,1));
        uint64_t ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            uint64_t start = q.front().second;
            for(int i=0; i<sz; ++i) {
                auto t = q.front(); q.pop();
                ans = max(ans, t.second - start + 1);
                if(t.first && t.first->left) {
                    q.push(make_pair(t.first->left, t.second*2));
                }
                if(t.first && t.first->right) {
                    q.push(make_pair(t.first->right, t.second*2+1));
                }
            }
        }
        return ans;
    }
};
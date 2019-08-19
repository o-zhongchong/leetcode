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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> tree_queue;
        if(root == nullptr)
            return 0;
        
        int max_sum = root->val, level=1;
        int cur_sum = 0, cur_level=1;
        tree_queue.push(make_pair(root,1));
        while( !tree_queue.empty() )
        {
            pair<TreeNode*,int> node = tree_queue.front();
            tree_queue.pop();

            if(node.first->left != nullptr)
                tree_queue.push( make_pair(node.first->left, node.second+1) );
            if(node.first->right != nullptr)
                tree_queue.push( make_pair(node.first->right, node.second+1) );
            
            if( node.second == cur_level)
            {
                cur_sum += node.first->val;
            }
            else if( node.second > cur_level)
            {
                if( cur_sum > max_sum )
                {
                    max_sum = cur_sum;
                    level = cur_level;
                }
                cur_sum = node.first->val;
                cur_level = node.second;
            }
        }

        if( cur_sum > max_sum )
            level = cur_level;
        return level;
    }
};
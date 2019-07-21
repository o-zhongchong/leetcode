/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode_t
{
    int num;
    TreeNode* node_p;
    TreeNode_t(int x, TreeNode* p) : num(x), node_p(p) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if ( S.empty() )
            return nullptr;

        vector<int> node_val, floor_val;
        stack<TreeNode_t> node_stack;

        if ( parse_str(S, node_val, floor_val) )
            return nullptr;

        TreeNode* root = new TreeNode( node_val[0] );
        node_stack.push( TreeNode_t( 0, root) );

        for (unsigned int i = 1; i < node_val.size(); ++i)
        {
            TreeNode_t node_top = node_stack.top();
            TreeNode* curr_node = new TreeNode(node_val[i]);

            if ( floor_val[i] > floor_val[node_top.num])
            {
                node_top.node_p->left = curr_node;
                node_stack.push(TreeNode_t(i, curr_node));
            }
            else
            {
                while ( !node_stack.empty() && floor_val[i] <= floor_val[node_top.num])
                {
                    node_stack.pop();
                    node_top = node_stack.top();
                }

                if (node_stack.empty())
                    return nullptr;

                node_top.node_p->right = curr_node;
                node_stack.pop();
                node_stack.push(TreeNode_t(i, curr_node));
            }
        }

        return root;
    }
private:
    int parse_str(string &s, vector<int> &node_val, vector<int> &floor_val)
    {
        node_val.clear();
        floor_val.clear();

        int start, end;
        int t_floor;
        start = end = 0;
        t_floor = 0;

        for (unsigned int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '-')
            {
                ++t_floor;
                start = i + 1;
            }
            else
            {
                end = i;
                if ( i + 1 < s.size() && s[i + 1] != '-' )
                    continue;
                else
                {
                    string str_val = s.substr(start, end - start + 1);
                    int val = atoi( str_val.c_str() );
                    node_val.push_back(val);
                    floor_val.push_back(t_floor);

                    start = i + 1;
                    t_floor = 0;
                }
            }
        }
        return 0;
    }
};
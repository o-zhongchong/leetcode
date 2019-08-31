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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        if( root == nullptr )
            return ret;
        
        ret.push_back(root);
        for( auto &node:to_delete )
        {
            del_node(ret, node, root);
        }
        
        return ret;
    }
protected:
    int del_node(vector<TreeNode*> &ret, int node, TreeNode* root)
    {
        int len = ret.size();
        for( int i=0; i < len; ++i )
        {
            TreeNode *p = ret[i];
            if( p->val == node)
            {
                if( p->left != nullptr )
                    ret.push_back( p->left );

                if( p->right != nullptr)
                    ret.push_back(p->right );
                
                if( p->val != root->val )
                {
                    if( root->left != nullptr && p->val == root->left->val)
                        root->left = nullptr;
                    if( root->right != nullptr && p->val == root->right->val)
                        root->right = nullptr;
                    delete p;
                    p = nullptr;
                }
                ret[i] = nullptr;
                
                ret.erase( ret.begin() + i );
                return 0;
            }
        }
        
        for( auto i = ret.begin(); i != ret.end(); ++i )
        {
            TreeNode *p = *i;
            TreeNode* r_left, *r_right;
            r_left = r_right = nullptr;
            
            if( del_child_node(p, node, r_left, r_right) == 0 )
            {
                if( r_left != nullptr)
                    ret.push_back(r_left);
                if( r_right != nullptr)
                    ret.push_back(r_right);
                return 0;
            }
        }
        
        return -1;
    }
    
    int del_child_node(TreeNode* father, int node, TreeNode* &r_left, TreeNode* &r_right)
    {
        if( father == nullptr)
            return -1;
        
        if( father->left != nullptr && father->left->val == node)
        {
            r_left = father->left->left;
            r_right = father->left->right;
            delete father->left;
            father->left = nullptr;
            return 0;
        }
        
        if( father->right != nullptr && father->right->val == node)
        {
            r_left = father->right->left;
            r_right = father->right->right;
            delete father->right;
            father->right = nullptr;
            return 0;
        }
        
        if( father->left != nullptr)
        {
            if( del_child_node(father->left, node, r_left, r_right) == 0)
                return 0;
        }
            
        if( father->right != nullptr)
        {
            if( del_child_node(father->right, node, r_left, r_right) == 0)
                return 0;
        }
        
        return -1;
    }
};
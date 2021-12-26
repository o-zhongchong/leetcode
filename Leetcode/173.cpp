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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    int next() {
        TreeNode* t = st.top(); st.pop();
        TreeNode* p = t->right;
        while(p) {
            st.push(p);
            p = p->left;
        }
        return t->val;
    }
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
};

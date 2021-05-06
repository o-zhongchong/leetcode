/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> list2vector(ListNode* head)
    {
        vector<int> ret;
        
        while(head != nullptr)
        {
            ret.push_back(head->val);
            head = head->next;
        }
        
        return ret;
    }
    
    TreeNode* vector2BST(vector<int> &nums, int i, int j)
    {
        if(i == j)
        {
            return new TreeNode(nums[i]);
        }
        else if(i > j)
        {
            return nullptr;
        }
        
        int mid = i + (j - i) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = vector2BST(nums, i, mid-1);
        ret->right = vector2BST(nums, mid+1, j);
        return ret;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums = list2vector(head);
        return vector2BST(nums, 0, nums.size() - 1);
    }
};
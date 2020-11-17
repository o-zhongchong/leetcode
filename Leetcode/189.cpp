class Solution {
public:
    void reverse(vector<int>& nums, int i, int j)
    {
        while(i < j)
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
        
        return;
    }
    
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || k % nums.size() == 0)
        {
            return;
        }
        
        int len = nums.size();
        reverse(nums, 0, len - (k % len) - 1);
        reverse(nums, len - (k % len), len - 1);
        reverse(nums, 0, len - 1);
        
        return;
    }
};
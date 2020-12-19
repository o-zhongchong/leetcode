class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i])
            {
                swap(nums[left++], nums[i]);
            }
        }
        
        return;
    }
};
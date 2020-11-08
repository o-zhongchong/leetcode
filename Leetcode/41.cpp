class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=0; i<len; ++i)
        {
            while(nums[i] > 0 && nums[i] <= len
              && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i=0; i<len; ++i)
        {
            if(i + 1 != nums[i])
            {
                return i + 1;
            }
        }
        
        return len + 1;
    }
};
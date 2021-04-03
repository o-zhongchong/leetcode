class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            for(int j=i+2; j<len; ++j)
            {
                if(nums[j] - nums[j-1] == nums[j-1] - nums[j-2])
                {
                    ++ret;
                }
                else
                {
                    break;
                }
            }
        }
        
        return ret;
    }
};
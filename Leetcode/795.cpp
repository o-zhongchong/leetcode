class Solution {
public:
    int count(vector<int> &nums, int bound)
    {
        int len = nums.size();
        int ret = 0;
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(nums[i] <= bound)
            {
                ++j;
                
                if(i == len-1)
                {
                    ret += (1+j)*j/2;
                    j=0;
                }
            }
            else
            {
                ret += (1+j)*j/2;
                j=0;
            }
        }
        
        return ret;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left-1);
    }
};
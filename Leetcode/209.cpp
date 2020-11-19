class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int len = nums.size();
        vector<int> sum(len, 0);
        sum[0] = nums[0];
        
        for(int i=1; i<len; ++i)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        
        for(int step = 1; step <= len; ++step)
        {
            for(int i = 0; i < len && i + step - 1 < len; ++i)
            {
                int subsum = 0;
                
                if(i == 0)
                {
                    subsum = sum[i + step - 1];
                }
                else
                {
                    subsum = sum[i + step - 1] - sum[i - 1];
                }
                
                if(subsum >= s)
                {
                    return step;
                }
            }
        }
        
        return 0;
    }
};
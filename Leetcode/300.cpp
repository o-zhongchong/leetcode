class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)
        {
            return 0;
        }
        
        vector<int> dp(len,1);
        int LIS = dp[0];
        
        for(int i=1; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            
            if(dp[i] > LIS)
            {
                LIS = dp[i];
            }
        }
        
        return LIS;
    }
};
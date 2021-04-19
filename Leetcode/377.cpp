class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        
        for(int i=1; i<=target; ++i)
        {
            for(auto n : nums)
            {
                if(i < n)
                {
                    break;
                }
                
                dp[i] += dp[i-n];
                dp[i] %= INT_MAX;
            }
        }
        
        return dp[target];
    }
};
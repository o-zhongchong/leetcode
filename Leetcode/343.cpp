class Solution {
public:
    vector<int> dp;
    
    Solution()
    {
        dp = vector<int>(59,0);
        dp[1] = dp[2] = 1;
        
        for(int i=3; i<59; ++i)
        {
            for(int j=1; j<i; ++j)
            {
                if(dp[j] * (i-j) > dp[i])
                {
                    dp[i] = dp[j] * (i-j);
                }
                
                if(j * (i-j) > dp[i])
                {
                    dp[i] = j * (i-j);
                }
            }
        }
    }
    
    int integerBreak(int n) {
        if(n <=0 || n > 58)
        {
            return 0;
        }
        
        return dp[n]; 
    }
};
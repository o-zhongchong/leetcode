class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        
        int len = prices.size();
        int k = 2;
        vector<vector<int>> dp(k+1, vector<int>(len, 0));
        
        for(int i = 1; i <= k; ++i)
        {
            int tmpMax = dp[i-1][0] - prices[0];
            
            for(int j=1; j<len; ++j)
            {
                dp[i][j] = prices[j] + tmpMax;
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
                tmpMax = max(dp[i-1][j] - prices[j], tmpMax);
            }
        }
        
        return dp[k][len-1];
    }
};
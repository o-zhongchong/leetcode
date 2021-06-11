class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        vector<int> prefix_sum(len+1,0);
        vector<vector<int>> dp(len, vector<int>(len,0));
        
        for(int i=1;i<len+1;++i)
        {
            prefix_sum[i] = prefix_sum[i-1] + stones[i-1];
        }
        
        for(int step=1; step<len; ++step)
        {
            for(int i=0; i<len-step; ++i)
            {
                int d1 = prefix_sum[i+step] - prefix_sum[i] - dp[i][i+step-1];
                int d2 = prefix_sum[i+step+1] - prefix_sum[i+1] - dp[i+1][i+step];
                dp[i][i+step] = max(d1, d2);
            }
        }
        
        return dp[0][len-1];
    }
};
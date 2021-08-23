class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int ret = 1;
        for(int i=2; i<n+1; ++i) {
            if(i & 1) {
                dp[i] = dp[(i-1)/2] + dp[i/2+1];
            }
            else {
                dp[i] = dp[i/2];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
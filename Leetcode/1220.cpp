class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[n+1][5];
        int M = 1e9 + 7;
        long long ret = 0;
        
        for(int i=0; i<5; ++i)
        {
            dp[1][i] = 1;
        }
        
        for(int i=2; i<=n; ++i)
        {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % M;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % M;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % M;
            dp[i][3] = dp[i-1][2] % M;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % M;
        }
        
        for(int i=0; i<5; ++i)
        {
            ret = (ret + dp[n][i]) % M;
        }
        
        return ret;
    }
};
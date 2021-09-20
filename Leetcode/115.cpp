class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() + 1;
        int n = t.size() + 1;
        if(m < n) return 0;
        const int M = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i) dp[i][0] = 1;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(i < j) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
                dp[i][j] %= M;
            }
        }
        return (int)dp[m-1][n-1];
    }
};
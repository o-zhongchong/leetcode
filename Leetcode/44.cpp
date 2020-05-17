class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        int **dp = new int*[m+1];
        for(int i=0; i<m+1; ++i)
        {
            dp[i] = new int[n+1];
        }
        
        for(int i=0; i<m+1; ++i)
        {
            for(int j=0; j<n+1; ++j)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) 
        {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];
        }
        
        for (int i = 1; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } 
                else 
                {
                    dp[i][j] = (s[i - 1] == p[j - 1] ||
                                p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
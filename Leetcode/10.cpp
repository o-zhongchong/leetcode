class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        int** dp=new int*[m+1];
        
        for(int i=0; i<m+1; ++i)
        {
            dp[i]= new int[n+1];
            memset(dp[i], 0, sizeof(int)*(n+1));
        }
        dp[0][0] = 1;
        
        for(int i=1; i<m+1; ++i)
        {
            for(int j=0; j<n+1; ++j)
            {
                if(p[i-1] == '*')
                {
                    if( i==1 )
                    {
                        dp[i][j] = 1;
                    }
                    else if( dp[i-2][j] )
                    {
                        dp[i][j] = 1;
                    }
                    else if( j-1>=0 && (p[i-2] == '.'|| p[i-2] == s[j-1]) )
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
                else
                {
                    if( j-1>=0 && (p[i-1] == '.' || p[i-1] == s[j-1]) )
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};
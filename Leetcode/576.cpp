class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n, 0)));
        int M = 1e9 + 7;
        int step[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        
        for(int k=1; k<=maxMove; ++k)
        {
            for(int i=0; i<m; ++i)
            {
                for(int j=0; j<n; ++j)
                {
                    long long cnt = 0;
                    
                    for(int t=0; t<4; ++t)
                    {
                        int p = i + step[t][0];
                        int q = j + step[t][1];
                        
                        if(p >= 0 && p < m && q >= 0 && q < n)
                        {
                            cnt += dp[k-1][p][q];
                        }
                        else
                        {
                            ++cnt;
                        }
                    }
                    
                    dp[k][i][j] = cnt % M;
                }
            }
        }
        
        return dp[maxMove][startRow][startColumn];
    }
};
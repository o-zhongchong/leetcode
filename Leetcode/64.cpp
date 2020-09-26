class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        
        if(m <= 0)
        {
            return 0;
        }
        
        int n = grid[0].size();
        int** dp = new int*[m];
        
        for(int i=0; i<m; ++i)
        {
            dp[i] = new int[n];
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                dp[i][j] = INT_MAX;
            }
        }
        
        int step[2][2] = {{-1,0}, {0,-1}};
        dp[0][0] = grid[0][0];
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                for(int k=0; k<2; ++k)
                {
                    int p = i + step[k][0];
                    int q = j + step[k][1];
                    
                    if(p >=0 && p < m  && q >=0 && q < n)
                    {
                        if(dp[i][j] == INT_MAX ||
                           dp[p][q] + grid[i][j] < dp[i][j])
                        {
                            dp[i][j] = dp[p][q] + grid[i][j];
                        }
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
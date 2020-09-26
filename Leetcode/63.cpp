class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        
        if(m <= 0)
        {
            return 0;
        }
        
        int n = obstacleGrid[0].size();
        
        int** dp = new int*[m];
        
        for(int i=0; i<m; ++i)
        {
            dp[i] = new int[n];
            memset(dp[i], 0, n*sizeof(int));
        }
        
        int step[2][2] = {{-1,0}, {0,-1}};
        
        if(obstacleGrid[0][0] == 0)
        {
            dp[0][0] = 1;
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                for(int k=0; k<2; ++k)
                {
                    int p = i + step[k][0];
                    int q = j + step[k][1];
                    
                    if(obstacleGrid[i][j] == 0 && p >=0 && p < m 
                      && q >=0 && q < n && obstacleGrid[p][q] == 0)
                    {
                        dp[i][j] += dp[p][q];
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};
class Solution {
public:
    int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp)
    {
        if(dp[x][y] > 0)
        {
            return dp[x][y];
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ret = 1;
        
        for(int i=0; i<4; ++i)
        {
            int p = x + step[i][0];
            int q = y + step[i][1];
            
            if(p >=0 && p < m && q >=0 && q < n && matrix[p][q] > matrix[x][y])
            {
                int r = dfs(matrix, p, q, dp);
                ret = max(ret, r + 1);
            }
        }
        
        dp[x][y] = ret;
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ret = 1;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                ret = max(ret, dfs(matrix, i, j, dp));
            }
        }
        
        return ret;
    }
};
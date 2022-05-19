class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& matrix, int x, int y, 
        vector<vector<int>>& dp) 
    {
        if (dp[x][y] > 0) return dp[x][y];
        int m = matrix.size();
        int n = matrix[0].size();
        int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        dp[x][y] = 1;
        for (int i=0; i<4; ++i) {
            int p = x + step[i][0];
            int q = y + step[i][1];
            if (p>=0 && p<m && q>=0 && q<n && matrix[x][y]>matrix[p][q]) {
                int r = dfs(matrix, p, q, dp);
                dp[x][y] = max(dp[x][y], r + 1);
            }
        }
        return dp[x][y];
    }
};
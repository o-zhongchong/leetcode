class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp[2];
        for(int i=0; i<2; ++i) {
            dp[i] = vector<vector<int>>(n, vector<int>(n,-1));
        }
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        int step[3] = {-1, 0, 1};
        int ret = dp[0][0][n-1];
        for(int i=1; i<m; ++i) {
            for(int x=0; x<n; ++x) {
                for(int y=0; y<n; ++y) {
                    for(int j=0; j<3; ++j) {
                        for(int k=0; k<3; ++k) {
                            int x0 = x + step[j];
                            int y0 = y + step[k];
                            if(x0 >= 0 && x0 < n && y0 >= 0 && y0 < n && dp[0][x0][y0] != -1) {
                                if(x == y) {
                                    dp[1][x][y] = max(dp[1][x][y], dp[0][x0][y0] + grid[i][x]);
                                } else {
                                    dp[1][x][y] = max(dp[1][x][y], dp[0][x0][y0] + grid[i][x] + grid[i][y]);
                                }
                                ret = max(ret, dp[1][x][y]);
                            }
                        }
                    }
                }
            }
            swap(dp[0], dp[1]);
        }
        return ret;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int step[8][2] = {
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
        };
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        if (grid[0][0] == 0) {
            q.push(make_pair(0,0));
            dp[0][0] = 1;
        }
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            int dist = dp[t.first][t.second];
            for (int i=0; i<8; ++i) {
                int x = t.first + step[i][0];
                int y = t.second + step[i][1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                    if (dist + 1 < dp[x][y]) {
                        dp[x][y] = dist + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        return dp[m-1][n-1] == INT_MAX ? -1 : dp[m-1][n-1];
    }
};
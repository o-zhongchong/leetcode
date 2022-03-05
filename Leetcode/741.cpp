class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); 
        g = &grid;
        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, helper(n - 1, n - 1, n - 1));
    }
private:
    int helper(int x1, int y1, int x2) {
        int y2 = x1 + y1 - x2;
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return -1;
        if (dp[x1][y1][x2] != INT_MIN) return dp[x1][y1][x2];
        if ((*g)[x1][y1] == -1 || (*g)[x2][y2] == -1) return dp[x1][y1][x2] = -1;
        if (x1 == 0 && y1 == 0) return dp[x1][y1][x2] = (*g)[0][0];
        int ans =  max(max(helper(x1-1, y1, x2), helper(x1-1, y1, x2-1)),
                       max(helper(x1, y1-1, x2), helper(x1, y1-1, x2-1)));
        if (ans < 0) return dp[x1][y1][x2] = -1;
        ans += (*g)[x1][y1];
        if (x1 != x2) ans += (*g)[x2][y2];
        return dp[x1][y1][x2] = ans;
    }
private:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> *g;
};
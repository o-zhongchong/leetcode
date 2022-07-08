class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, 
        int m, int n, int target)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(target+1, INT_MAX)));
        if (houses[0] != 0) {
            dp[0][houses[0]][1] = 0;
        } else {
            for (int j=1; j<n+1; ++j) {
                dp[0][j][1] = cost[0][j-1];
            }
        }
        for (int i=1; i<m; ++i) {
            for (int j=0; j<n+1; ++j) {
                for (int k=0; k<target+1; ++k) {
                    if (dp[i-1][j][k] == INT_MAX) continue;
                    if (houses[i] != 0) {
                        if (houses[i] == j) {
                            dp[i][houses[i]][k] = min(dp[i][houses[i]][k], dp[i-1][j][k]);
                        } else if(houses[i] != j && k+1 < target+1) {
                            dp[i][houses[i]][k+1] = min(dp[i][houses[i]][k+1], dp[i-1][j][k]);
                        }
                    } else {
                        for (int c=1; c<n+1; ++c) {
                            if (c == j) {
                                dp[i][c][k] = min(dp[i][c][k], dp[i-1][j][k] + cost[i][c-1]);
                            } else if (c != j && k+1 < target+1){
                                dp[i][c][k+1] = min(dp[i][c][k+1], dp[i-1][j][k] + cost[i][c-1]);
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int j=1; j<n+1; ++j) {
            ans = min(ans, dp[m-1][j][target]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
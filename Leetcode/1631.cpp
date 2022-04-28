class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        int step[4][2] = {{0,-1}, {0,1}, {-1, 0}, {1,0}};
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        vector<int> t1(3, 0), t2(3, 0);
        while(!pq.empty()) {
            t1 = pq.top(); pq.pop();
            int effort = t1[0];
            int x1 = t1[1];
            int y1 = t1[2];
            if(x1 == m-1 && y1 == n-1) return effort;
            for(int i=0; i<4; ++i) {
                int x2 = x1 + step[i][0];
                int y2 = y1 + step[i][1];
                if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                    t2[0] = max(effort, abs(heights[x2][y2] - heights[x1][y1]));
                    t2[1] = x2;
                    t2[2] = y2;
                    if(t2[0] < dp[x2][y2]) {
                        dp[x2][y2] = t2[0];
                        pq.push(t2);
                    }
                }
            }
        }
        return -1;
    }
};
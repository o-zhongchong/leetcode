class Comparator
{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> pq;
        int step[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int ret = 0;
        pq.push({grid[0][0], 0});
        visited[0][0] = true;
        
        while(!pq.empty())
        {
            int i = pq.top().second / N;
            int j = pq.top().second % N;
            pq.pop();
            ret = max(ret, grid[i][j]);
            dp[i][j] = ret;
            
            for(int k=0; k<4; ++k)
            {
                int m = i + step[k][0];
                int n = j + step[k][1];
                
                if(m >= 0 && m < N && n >= 0 && n < N && !visited[m][n])
                {
                    visited[m][n] = true;
                    pq.push(make_pair(grid[m][n], m*N+n));
                }
            }
        }
        
        return dp[N-1][N-1];
    }
};
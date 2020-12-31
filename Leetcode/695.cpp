class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        int step[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int ret = 1;
        grid[i][j] = 2;
        
        for(int k=0; k<4; ++k)
        {
            int p = i + step[k][0];
            int q = j + step[k][1];
            
            if(p >= 0 && p < m && q >= 0 && q < n && grid[p][q] == 1)
            {
                ret += dfs(grid, p, q, m, n);
            }
        }
        
        return ret;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int r = dfs(grid, i, j, m, n);
                    ret = max(ret, r);
                }
            }
        }
        
        return ret;
    }
};
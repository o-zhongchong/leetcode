class Solution {
public:
    int find(int* ds, int x)
    {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    
    int merge(int* ds, int x, int y)
    {
        int fx = find(ds, x);
        int fy = find(ds, y);
        
        if(fx != fy)
        {
            ds[fx] = fy;
            return 1;
        }
        
        return 0;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        
        if(m <= 0)
        {
            return 0;
        }
        
        int n = grid[0].size();
        int step[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int* ds = new int[m*n];
        
        for(int i=0; i<m*n; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    for(int k=0; k<4; ++k)
                    {
                        int p = i + step[k][0];
                        int q = j + step[k][1];
                        
                        if(p >= 0 && p < m && q >= 0 && q < n
                           && grid[p][q] == '1')
                        {
                            merge(ds, i*n+j, p*n+q);
                        }
                    }
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int k = i*n + j;
                
                if(grid[i][j] == '1' && find(ds, k) == k)
                {
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
};
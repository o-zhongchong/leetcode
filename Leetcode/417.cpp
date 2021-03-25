class Solution {
public:
    int dfs(vector<vector<int>> &matrix, int x, int y, int pre, vector<vector<bool>> &visited)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int step[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        if(x >=0 && x < m && y >=0 && y < n && !visited[x][y] && matrix[x][y] >= pre)
        {
            visited[x][y] = true;
        }
        else
        {
            return -1;
        }
        
        for(int i=0; i<4; ++i)
        {
            int p = x + step[i][0];
            int q = y + step[i][1];
            dfs(matrix, p, q, matrix[x][y], visited);
        }
        
        return 0;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
        {
            return {};
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> ret;
        
        for(int i=0; i<m; ++i)
        {
            dfs(matrix, i, 0, INT_MIN, pacific);
            dfs(matrix, i, n-1, INT_MIN, atlantic);
        }
        
        for(int j=0; j<n; ++j)
        {
            dfs(matrix, 0, j, INT_MIN, pacific);
            dfs(matrix, m-1, j, INT_MIN, atlantic);
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ret.push_back({i,j});
                }
            }
        }
        
        return ret;
    }
};
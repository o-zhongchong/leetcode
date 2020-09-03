class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> puzzle;
        vector<int> row(2*n, 0);
        vector<int> col(2*n, 0);
        vector<int> x(2*n, 0);
        vector<int> y(2*n, 0);
        
        for(int i = 0; i < n; ++i)
        {
            puzzle.push_back(string(n,'.'));
        }
        
        solver(puzzle, 0, n, row, col, x, y, ret);
        
        return ret;
    }
    
    int solver(vector<string>& puzzle, int i, int n, vector<int>& row,
              vector<int>& col, vector<int>& x, vector<int>& y, 
              vector<vector<string>>& ret)
    {
        if(i < 0 || n <= 0)
        {
            return -1;
        }
        
        if(i == n)
        {
            ret.push_back(puzzle);
            return 0;
        }
        
        for(int j = 0; j < n; ++j)
        {
            if(row[i] || col[j] || x[n-1-i+j] || y[i+j])
            {
                continue;
            }
            
            puzzle[i][j] = 'Q';
            row[i] = 1;
            col[j] = 1;
            x[n-1-i+j] = 1;
            y[i+j] = 1;
            
            solver(puzzle, i+1, n, row, col, x, y, ret);
            
            puzzle[i][j] = '.';
            row[i] = 0;
            col[j] = 0;
            x[n-1-i+j] = 0;
            y[i+j] = 0;
        }
        
        return 0;
    }
};
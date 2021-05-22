class Solution {
public:
    int dfs(vector<string> &chessboard, int j, vector<vector<int>> &stat,
            vector<vector<string>> &ret)
    {
        int n = chessboard.size();
        
        if(j >= n)
        {
            ret.push_back(chessboard);
            return 0;
        }
        
        for(int i=0; i<n; ++i)
        {
            if(!stat[0][i] && !stat[1][j] && !stat[2][n-1-i+j] && !stat[3][i+j])
            {
                stat[0][i] = stat[1][j] = stat[2][n-1-i+j] = stat[3][i+j] = 1;
                chessboard[i][j] = 'Q';
                dfs(chessboard, j+1, stat, ret);
                chessboard[i][j] = '.';
                stat[0][i] = stat[1][j] = stat[2][n-1-i+j] = stat[3][i+j] = 0;
            }
        }
        
        return 0;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> stat;
        vector<vector<string>> ret;
        vector<string> chessboard(n, string(n,'.'));
        
        stat.push_back(vector<int>(n, 0));
        stat.push_back(vector<int>(n, 0));
        stat.push_back(vector<int>(2*n-1, 0));
        stat.push_back(vector<int>(2*n-1, 0));
        
        dfs(chessboard, 0, stat, ret);
        return ret;
    }
};
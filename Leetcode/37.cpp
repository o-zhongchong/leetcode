class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n != 9)
            return;
        
        int row[9][9];
        int col[9][9];
        int box[9][9];
        
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                row[i][j] = col[i][j] = box[i][j] = 0;
            }
        }
        
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] != '.')
                {
                    int digit = board[i][j] - '1';
                    int n = (i/3)*3 + j/3; 
                    ++row[i][digit];
                    ++col[j][digit];
                    ++box[n][digit];
                }
            }
        }
        
        vector<vector<char>> ret;
        int flag = false;
        dfs(board, 0, row, col, box, ret, flag);
        
        if(flag)
        {
            board = ret;
        }
        
        return;
    }
    
    void dfs(vector<vector<char>>& board, int x,
             int (*row)[9], int (*col)[9], int (*box)[9],
             vector<vector<char>>& ret, int& f)
    {
        if(x >= 81)
        {
            f = true;
            ret = board;
            return;
        }
        
        int i = x / 9;
        int j = x % 9;
        int n = (i/3)*3 + j/3; 

        if(board[i][j] == '.')
        {
            for(int d = 1; d <= 9; ++d)
            {
                if(row[i][d-1] == 0 && col[j][d-1] == 0
                  && box[n][d-1] == 0)
                {
                    ++row[i][d-1];
                    ++col[j][d-1];
                    ++box[n][d-1];
                    board[i][j] = d - 1 + '1';
                    dfs(board, x+1, row, col, box, ret, f);
                    board[i][j] = '.';
                    --row[i][d-1];
                    --col[j][d-1];
                    --box[n][d-1];
                }
            }
        }
        else
        {
            dfs(board, x+1, row, col, box, ret, f);
        }
        
        return;
    }
};
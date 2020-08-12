class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int box[9][9];
        
        //init digit count
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                row[i][j] = col[i][j] = box[i][j] = 0;
            }
        }
        
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9')
                {
                    int digit = board[i][j] - '1';
                    int n = (i/3)*3 + j/3; 
                    ++row[i][digit];
                    ++col[j][digit];
                    ++box[n][digit];
                    
                    if(row[i][digit] > 1 || col[j][digit] > 1
                      || box[n][digit] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
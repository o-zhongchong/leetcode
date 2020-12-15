class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty())
        {
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        int step[8][2] = {{0, -1}, {0, 1}, {-1, -1}, {-1, 0},
                          {-1, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int cnt = 0;
                
                for(int k=0; k<8; ++k)
                {
                    int p = i + step[k][0];
                    int q = j + step[k][1];
                    
                    if(p >= 0 && p < m && q >=0 && q < n && 
                       (board[p][q] == 1 || board[p][q] == 2))
                    {
                        ++cnt;
                    }
                }
                
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3))
                {
                    board[i][j] = 2;
                }
                
                if(board[i][j] == 0 && cnt == 3)
                {
                    board[i][j] = 3;
                }
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                board[i][j] %= 2;
            }
        }
        
        return;
    }
};
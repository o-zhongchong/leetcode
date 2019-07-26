class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        for(unsigned int i=0; i<board.size(); ++i)
            for(unsigned int j=0; j<board[i].size(); ++j)
            {
                if( board[i][j] == '.')
                    continue;
                if( i>0 && board[i-1][j] == 'X')
                    continue;
                if( j>0 && board[i][j-1] == 'X')
                    continue;
                ++ret;
            }
        return ret;
    }
};
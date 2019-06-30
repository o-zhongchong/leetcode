class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        for(int startX = 0; startX < 8; ++startX)
            for(int startY = 0; startY < 8; ++startY)
                if(board[startX][startY] == 'R')
                {
                    int pos = startY - 1;
                    while(pos >= 0)
                    {
                        if(board[startX][pos] == 'p')
                        {
                            ++count;
                            break;
                        }
                        else if(board[startX][pos] == 'B')
                            break;
                        --pos;
                    }

                    pos = startY + 1;
                    while(pos < 8)
                    {
                        if(board[startX][pos] == 'p')
                        {
                            ++count;
                            break;
                        }
                        else if(board[startX][pos] == 'B')
                            break;
                        ++pos;
                    }

                    pos = startX - 1;
                    while(pos >= 0)
                    {
                        if(board[pos][startY] == 'p')
                        {
                            ++count;
                            break;
                        }
                        else if(board[pos][startY] == 'B')
                            break;
                        --pos;
                    }

                    pos = startX + 1;
                    while(pos < 8)
                    {
                        if(board[pos][startY] == 'p')
                        {
                            ++count;
                            break;
                        }
                        else if(board[pos][startY] == 'B')
                            break;
                        ++pos;
                    }
                }
        return count;
    }
};


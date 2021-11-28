class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int M = board.size();
        int N = board[0].size();
        int step[4][2] = {
            {0,-1},{0,1},{-1,0},{1,0}
        };
        queue<pair<int,int>> taskq;
        for(int i=0; i<M; ++i) {
            if(board[i][0] == 'O') {
                board[i][0] = '?';
                taskq.push(make_pair(i,0));
            }
            if(board[i][N-1] == 'O') {
                board[i][N-1] = '?';
                taskq.push(make_pair(i,N-1));
            }
        }
        for(int j=0; j<N; ++j) {
            if(board[0][j] == 'O') {
                board[0][j] = '?';
                taskq.push(make_pair(0,j));
            }
            if(board[M-1][j] == 'O') {
                board[M-1][j] = '?';
                taskq.push(make_pair(M-1,j));
            }
        }
        while(!taskq.empty()) {
            auto n = taskq.front();
            taskq.pop();
            for(int k=0; k<4; ++k) {
                int p = n.first + step[k][0];
                int q = n.second + step[k][1];
                if(p >=0 && p < M && q >=0 && q < N) {
                    if(board[p][q] == 'O') {
                        board[p][q] = '?';
                        taskq.push(make_pair(p,q));
                    }
                }
            }
        }
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '?') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
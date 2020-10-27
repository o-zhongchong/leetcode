class Solution {
public:
    bool dfs(vector<vector<char>>& board, int** visit,
             string& word, int i, int j, int layer)
    {
        if(layer >= word.size() - 1)
        {
            return true;
        }
        
        if(board[i][j] != word[layer])
        {
            return false;
        }
        
        int m = board.size();
        int n = board[0].size();
        int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        visit[i][j] = 1;
        
        for(int t=0; t<4; ++t)
        {
            int p = i + step[t][0];
            int q = j + step[t][1];
            
            if(p < 0 || p >= m || q < 0 || q >= n)
            {
                continue;
            }
            
            if(visit[p][q] == 0 && board[p][q] == word[layer+1])
            {
                if(dfs(board, visit, word, p, q, layer+1))
                {
                    visit[i][j] = 0;
                    return true;
                }
            }
        }
        
        visit[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
        {
            return true;
        }
        
        if(board.empty() || board[0].empty())
        {
            return false;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        if(word.size() > m * n)
        {
            return false;
        }
        
        int** visit = new int*[m];
        
        for(int i=0; i<m; ++i)
        {
            visit[i] = new int[n];
            memset(visit[i], 0, sizeof(int) * n);
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, visit, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
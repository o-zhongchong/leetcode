class Solution {
public:
    int find(int* ds, int x)
    {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    
    int merge(int* ds, int x, int y)
    {
        int fx = find(ds, x);
        int fy = find(ds, y);
        
        if(fx != fy)
        {
            ds[fx] = fy;
            return 1;
        }
        
        return 0;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        
        if(m <= 0)
        {
            return;
        }
        
        int n = board[0].size();
        int step[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int* ds = new int[m*n];
        
        for(int i=0; i<m*n; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    for(int k=0; k<4; ++k)
                    {
                        int p = i + step[k][0];
                        int q = j + step[k][1];
                        
                        if(p >= 0 && p < m && q > 0 && q < n
                           && board[p][q] == 'O')
                        {
                            merge(ds, i*n+j, p*n+q);
                        }
                    }
                }
            }
        }
        
        unordered_set<int> myset;
        
        for(int i=0; i<n; ++i)
        {
            if(board[0][i] == 'O')
            {
                int x = find(ds, i);
                myset.insert(x);
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            if(board[m-1][i] == 'O')
            {
                int x = find(ds, (m-1)*n+i);
                myset.insert(x);
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            if(board[i][0] == 'O')
            {
                int x = find(ds, i*n);
                myset.insert(x);
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            if(board[i][n-1] == 'O')
            {
                int x = find(ds, i*n+n-1);
                myset.insert(x);
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    int x = find(ds, i*n+j);
                    
                    if(myset.find(x) == myset.end())
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
        
        return;
    }
};
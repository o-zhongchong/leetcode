class Solution {
public:
    int find(int* ds, int x)
    {
        return x == ds[x] ? x : ds[x] = find(ds,ds[x]);
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
    
    int mergeTop(vector<string>& grid, int N, int i, int j, int* ds)
    {
        int p = i - 1;
        int q = j;
        
        if(p < 0)
        {
            return 0;
        }
        
        int n1 = (i*N + j) * 2;
        int n2 = (p*N + q) * 2 + 1;
        
        if(grid[i][j] == '\\')
        {
            ++n1;
        }
        
        if(grid[p][q] == '\\')
        {
            --n2;
        }
           
        merge(ds, n1, n2);
           
        return 1;
    }
           
    int mergeDown(vector<string>& grid, int N, int i, int j, int* ds)
    {
        int p = i + 1;
        int q = j;
        
        if(p >= N)
        {
            return 0;
        }
        
        int n1 = (i*N + j) * 2 + 1;
        int n2 = (p*N + q) * 2;
        
        if(grid[i][j] == '\\')
        {
            --n1;
        }
           
        if(grid[p][q] == '\\')
        {
            ++n2;
        }
           
        merge(ds, n1, n2);
           
        return 1;
    }
    
    int mergeLeft(vector<string>& grid, int N, int i, int j, int* ds)
    {
        int p = i;
        int q = j - 1;
        
        if(q < 0)
        {
            return 0;
        }
        
        int n1 = (i*N + j) * 2;
        int n2 = (p*N + q) * 2 + 1;
        merge(ds, n1, n2);
        
        return 1;
    }
    
    int mergeRight(vector<string>& grid, int N, int i, int j, int* ds)
    {
        int p = i;
        int q = j + 1;
        
        if(q >= N)
        {
            return 0;
        }
        
        int n1 = (i*N + j) * 2 + 1;
        int n2 = (p*N + q) * 2;
        merge(ds, n1, n2);
        
        return 1;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        int* ds = new int[2*N*N];
        
        for(int i=0; i<2*N*N; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                int n = (i*N + j) * 2;
                
                if(grid[i][j] == ' ')
                {
                    merge(ds, n, n+1);
                }
                
                mergeTop(grid, N, i, j, ds);
                mergeDown(grid, N, i, j, ds);
                mergeLeft(grid, N, i, j, ds);
                mergeRight(grid, N, i, j, ds);
            }
        }
        
        int cnt = 0;
        
        for(int i=0; i<2*N*N; ++i)
        {
            if(i == find(ds, i))
            {
                ++cnt;
            }
        }
        
        return cnt;
    }
};
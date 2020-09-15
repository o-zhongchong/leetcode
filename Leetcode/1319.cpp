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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int* ds = new int[n];
        
        for(int i=0; i<n; ++i)
        {
            ds[i] = i;
        }
        
        int m = connections.size();
        int e = 0, g = 0;
        
        for(int i=0; i<m; ++i)
        {
            if(!merge(ds, connections[i][0], connections[i][1]))
            {
                ++e;
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            if(ds[i] == i)
            {
                ++g;
            }
        }
        
        if(g-1 <= e)
        {
            return g-1;
        }
        
        return -1;
    }
};
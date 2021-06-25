class Solution {
public:
    int find(vector<int> &ds, int x)
    {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    
    int merge(vector<int> &ds, int x, int y)
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ds(n+1, 0);
        
        for(int i=0; i<=n; ++i)
        {
            ds[i] = i;
        }
        
        for(auto &e : edges)
        {
            if(!merge(ds, e[0], e[1]))
            {
                return {e[0], e[1]};
            }
        }
        
        return {};
    }
};
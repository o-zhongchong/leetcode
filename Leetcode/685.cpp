class Solution {
public:
    int getRoot(int* ds, int x)
    {
        return x == ds[x] ? x : getRoot(ds, ds[x]);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        
        if(len <= 0)
        {
            return vector<int>();
        }
        
        int* ds = new int[len+1];
        vector<int> r1, r2;
        
        for(int i=0; i<len+1; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            if(ds[edges[i][1]] == edges[i][1])
            {
                ds[edges[i][1]] = edges[i][0];
            }
            else
            {
                r1 = vector<int>{ds[edges[i][1]], edges[i][1]};
                r2 = vector<int>{edges[i][0], edges[i][1]};
                break;
            }
        }
        
        for(int i=0; i<len+1; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            int fx = getRoot(ds, edges[i][0]);
            int fy = ds[edges[i][1]];
            
            if(fy != edges[i][1])
            {
                continue;
            }
            
            if(fx == edges[i][1])
            {
                return r1.empty() ? vector<int>{edges[i][0],edges[i][1]} : r1;
            }
            else
            {
                ds[edges[i][1]] = edges[i][0];
            }
        }
        
        return r2;
    }
};
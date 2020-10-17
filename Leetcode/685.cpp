class Solution {
public:
    int find(int* ds, int x, int y)
    {
        if(ds[x] == y)
        {
            return 1;
        }
        
        if(ds[x] == x)
        {
            return 0;
        }
        
        return find(ds, ds[x], y);
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
            if(ds[edges[i][1]] != edges[i][1])
            {
                continue;
            }
            
            if(find(ds, edges[i][0], edges[i][1]))
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
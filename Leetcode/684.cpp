class Solution {
public:
    int find(int* ds, int x)
    {
        return x == ds[x] ? x : ds[x] = find(ds,ds[x]);
    }
    
    int merge(int* ds, int x, int y)
    {
        int fx = find(ds,x);
        int fy = find(ds,y);
        
        if(fx != fy)
        {
            ds[fx] = fy;
            return 1;
        }
        
        return 0;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<int> ret;
        int* ds = new int[len];
        
        for(int i=0; i<len; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            if(!merge(ds,edges[i][0]-1, edges[i][1]-1))
            {
                ret.push_back(edges[i][0]);
                ret.push_back(edges[i][1]);
            }
        }
        
        return ret;
    }
};
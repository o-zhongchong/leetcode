class Solution {
public:
    int find(int* ds, int x)
    {
        return x == ds[x] ? x : ds[x] = find(ds, ds[x]);
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
    
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        int* ds = new int[len];
        
        for(int i=0; i<len; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<len; ++j)
            {
                if(i != j && M[i][j])
                {
                    merge(ds,i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(i == ds[i])
            {
                ++cnt;
            }
        }
        
        return cnt;
    }
};
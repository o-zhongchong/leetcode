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
    
    int removeStones(vector<vector<int>>& stones) {
        int cnt = stones.size();
        int ret = 0;
        int* ds = new int[cnt];
        
        for(int i=0; i<cnt; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<cnt; ++i)
        {
            for(int j=i+1; j<cnt; ++j)
            {
                if(stones[i][0] == stones[j][0] ||
                  stones[i][1] == stones[j][1])
                {
                    merge(ds, i, j);
                }
            }
        }
        
        for(int i=0; i<cnt; ++i)
        {
            if(i == find(ds,i))
            {
                ++ret;
            }
        }
        
        return cnt - ret;
    }
};
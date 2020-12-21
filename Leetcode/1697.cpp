class Solution {
public:
    int find(vector<int>& ds, int x)
    {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    
    int merge(vector<int>& ds, int x, int y)
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
    
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,           vector<vector<int>>& queries) 
    {
        if(n <= 0)
        {
            return {};
        }
        
        vector<int> ds(n, 0);
        int len1 = edgeList.size();
        int len2 = queries.size();
        vector<bool> ret(len2, false);
        
        for(int i=0; i<n; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len2; ++i)
        {
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        
        for(int i=0, j=0; i<len2; ++i)
        {
            while(j < len1 && edgeList[j][2] < queries[i][2])
            {
                merge(ds, edgeList[j][0], edgeList[j][1]);
                ++j;
            }
            
            if(find(ds, queries[i][0]) == find(ds, queries[i][1]))
            {
                ret[queries[i][3]] = 1;
            }
        }
        
        return ret;
    }
};
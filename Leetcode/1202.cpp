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
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        int* ds = new int[n];
        vector<string> str(n, "");
        
        for(int i=0; i<n; ++i)
        {
            ds[i] = i;
        }
        
        for(auto pair: pairs)
        {
            merge(ds, pair[0],pair[1]);
        }
        
        for(int i=0; i<n; ++i)
        {
            int j = find(ds, i);
            str[j].push_back(s[i]);
        }
        
        
        for(int i=0; i<n; ++i)
        {
            if(str[i] != "")
            {
                sort(str[i].begin(), str[i].end());
            }
        }
        
        int* c = new int[n];
        memset(c, 0, n*sizeof(int));
        
        for(int i=0; i<n; ++i)
        {
            int j = find(ds, i);
            s[i] = str[j][c[j]];
            ++c[j];
        }
        
        return s;
    }
};
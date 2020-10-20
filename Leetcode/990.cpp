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
    
    bool equationsPossible(vector<string>& equations) {
        int* ds = new int[26];
        int len = equations.size();
        
        for(int i=0; i<26; ++i)
        {
            ds[i] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            string symbol = equations[i].substr(1,2);
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            
            if(symbol == "==")
            {
                merge(ds, x, y);
            }
        }
        
        for(int i=0; i<len; ++i)
        {
            string symbol = equations[i].substr(1,2);
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            int fx = find(ds, x);
            int fy = find(ds, y);
            
            if(symbol == "!=" && fx == fy)
            {
                return false;
            }
        }
        
        return true;
    }
};
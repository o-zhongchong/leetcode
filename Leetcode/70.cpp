class Solution {
public:
    int climbStairs(int n) {
        vector<vector<long long>> a = {{1}, {1}};
        vector<vector<long long>> q = {{1,1}, {1,0}};
        q = matrixPow(q, n);
        vector<vector<long long>> ret = matrixMultiply(q, a);
        return ret[1][0];
    }
    
    vector<vector<long long>> matrixPow(vector<vector<long long>> base, int n)
    {
        int m = base.size();
        vector<vector<long long>> ret(m, vector<long long>(m, 0));
        
        for(int i=0; i<m; ++i)
        {
            ret[i][i] = 1;
        }
        
        while(n)
        {
            if(n & 1)
            {
                ret = matrixMultiply(ret, base);
            }
            
            base = matrixMultiply(base, base);
            n >>= 1;
        }
        
        return ret;
    }
    
    vector<vector<long long>> matrixMultiply(vector<vector<long long>> &a, 
                                             vector<vector<long long>> &b)
    {
        if(a.empty() || a[0].empty() || b.empty() || b[0].empty())
        {
            return {};
        }
        
        int m = a.size();
        int n = a[0].size();
        int p = b.size();
        int q = b[0].size();
        vector<vector<long long>> ret(m, vector<long long>(q,0));
        
        if(n != p)
        {
            return {};
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<q; ++j)
            {
                for(int k=0; k<n; ++k)
                {
                    ret[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        return ret;
    }
};
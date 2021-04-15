class Solution {
public:
    int fib(int n) {
        vector<vector<int>> A0 = {{1}, {0}};
        vector<vector<int>> M = {{1,1}, {1,0}};
        vector<vector<int>> ret = matrix_pow(M, n);
        ret = matrix_multiply(ret, A0);
        return ret[1][0];
    }
    
    vector<vector<int>> matrix_pow(vector<vector<int>> M, int n)
    {
        if(n < 0 || M.empty() || M[0].empty() || M.size() != M[0].size())
        {
            return {};
        }
        
        int m = M.size();
        vector<vector<int>> ret(m, vector<int>(m, 0));
        
        for(int i=0; i<m; ++i)
        {
            ret[i][i] = 1;
        }
        
        while(n)
        {
            if(n & 1)
            {
                ret = matrix_multiply(ret, M);
            }
            
            n >>= 1;
            M = matrix_multiply(M, M);
        }
        
        return ret;
    }
    
    vector<vector<int>> matrix_multiply(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        if(A.empty() || A[0].empty() || B.empty() || B[0].empty() || A[0].size() != B.size())
        {
            return {};
        }
        
        int m = A.size();
        int n = A[0].size();
        int p = B.size();
        int q = B[0].size();
        vector<vector<int>> ret(m, vector<int>(q, 0));
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<q; ++j)
            {
                for(int k=0; k<n; ++k)
                {
                    ret[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return ret;
    }
};
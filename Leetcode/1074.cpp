class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        int ret = 0;
        
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for (int i = 1; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                for (int p = 1; p <= i; ++p) 
                {
                    for (int q = 1; q <= j; ++q) 
                    {
                        int s = sum[i][j] + sum[p-1][q-1] - sum[i][q-1] - sum[p-1][j];
                        
                        if(s == target)
                        {
                            ++ret;
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};
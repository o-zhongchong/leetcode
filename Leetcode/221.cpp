class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ret = 0;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(matrix[i][j] == '0')
                {
                    continue;
                }
                
                dp[i][j] = 1;
                int p = i-1, q = j-1;
                
                if(p < 0 || p >= m || q < 0 || q >= n || dp[p][q] == 0)
                {
                    if(dp[i][j] * dp[i][j] > ret)
                    {
                        ret = dp[i][j] * dp[i][j];
                    }
                    continue;
                }
                
                int step = 0;
                
                for(int k=step+1; k<=dp[p][q]; ++k)
                {
                    if(i-k < 0 || j-k < 0 ||
                       matrix[i-k][j] == '0' || matrix[i][j-k] == '0')
                    {
                        break;
                    }
                    else
                    {
                        step = k;
                    }
                }
                
                if(step)
                {
                    dp[i][j] = step + 1;
                }
                
                if(dp[i][j] * dp[i][j] > ret)
                {
                    ret = dp[i][j] * dp[i][j];
                }
            }
        }
        
        return ret;
    }
};
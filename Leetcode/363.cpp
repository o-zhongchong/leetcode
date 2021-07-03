class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int sum[m][n];
        int ret = INT_MIN;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int t = matrix[i][j];
                if(i > 0) t += sum[i-1][j];
                if(j > 0) t += sum[i][j-1];
                if(i > 0 && j > 0) t -= sum[i-1][j-1];
                sum[i][j] = t;
                
                for(int p=0; p<=i; ++p){
                    for(int q=0; q<=j; ++q)
                    {
                        int s = sum[i][j];
                        if(p > 0) s -= sum[p-1][j];
                        if(q > 0) s -= sum[i][q-1];
                        if(p > 0 && q > 0) s += sum[p-1][q-1];
                        if(s <= k) ret = max(ret, s);
                    }
                }
            }
        }
        
        return ret;
    }
};
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            for(int j=i; j<n; ++j)
            {
                unordered_map<int,int> mymap;
                mymap[0] = 1;
                int sum = 0;
                
                for(int k=0; k<m; ++k)
                {
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                    ret += mymap[sum - target];
                    ++mymap[sum];
                }
            }
        }
        
        return ret;
    }
};
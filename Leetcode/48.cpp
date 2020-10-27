class Solution {
public:
    void swap1(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i > j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
    
    void swap2(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; ++i)
        {
            int j = 0;
            int k = n-1;
            
            while(j < k)
            {
                swap(matrix[i][j], matrix[i][k]);
                ++j;
                --k;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
        {
            return;
        }
        
        swap1(matrix);
        swap2(matrix);
        
        return;
    }
};
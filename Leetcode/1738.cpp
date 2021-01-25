class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        k = m * n - k + 1;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                matrix[i][j] ^= matrix[i][j-1];
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                matrix[i][j] ^= matrix[i-1][j];
            }
        }
        
        priority_queue<int> min_heap;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                min_heap.push(matrix[i][j]);
                
                while(min_heap.size() > k)
                {
                    min_heap.pop();
                }
            }
        }
        
        return min_heap.top();
    }
};
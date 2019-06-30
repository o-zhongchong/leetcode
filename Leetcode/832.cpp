class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for( int i = 0; i < A.size(); ++i)
        {
            int j = 0, k = A[i].size() - 1;
            while( j < k )
            {
                swap(A[i][j], A[i][k]);
                ++j;
                --k;
            }
        }
        
        for( int i = 0; i < A.size(); ++i )
        {
            for( int j = 0; j < A[i].size(); ++j)
            {
                A[i][j] = A[i][j] ^ 1;
            }
        }
        
        return A;
    }
};
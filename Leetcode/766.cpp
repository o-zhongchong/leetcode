class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if( matrix.empty() )
            return false;
        
        unsigned int M = matrix.size();
        unsigned int N = matrix[0].size();
        
        for(unsigned int i=0; i<M; ++i)
        {
            unsigned int x=i+1, y=0+1;
            while(x<M && y<N)
            {
                if(matrix[x][y] != matrix[i][0])
                    return false;
                ++x;
                ++y;
            }
        }
        
        for(unsigned int j=0; j<N; ++j)
        {
            unsigned int x=0+1, y=j+1;
            while(x<M && y<N)
            {
                if(matrix[x][y] != matrix[0][j])
                    return false;
                ++x;
                ++y;
            }
        }
        return true;
    }
};
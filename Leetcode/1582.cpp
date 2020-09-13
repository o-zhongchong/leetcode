class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> x(row,0);
        vector<int> y(col,0);
        int cnt = 0;
        
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(mat[i][j] == 1)
                {
                    ++x[i];
                    ++y[j];
                }
            }
        }
        
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(mat[i][j] == 1 && x[i] == 1 && y[j] == 1)
                {
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
};
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty() || matrix[0].empty())
        {
            return;
        }
        
        data = matrix;
        int m = data.size();
        int n = data[0].size();
        
        for(int i=1; i<m; ++i)
        {
            data[i][0] += data[i-1][0];
        }
        
        for(int j=1; j<n; ++j)
        {
            data[0][j] += data[0][j-1];
        }
        
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1, s2, s3, s4;
        s1 = s2 = s3 = s4 = 0;
        
        if(row1 - 1 >= 0 && col1 - 1 >= 0)
        {
            s1 = data[row1-1][col1-1];
        }
        
        if(col1 - 1 >= 0)
        {
            s2 = data[row2][col1-1];
        }
        
        if(row1 - 1 >= 0)
        {
            s3 = data[row1-1][col2];
        }
        
        s4 = data[row2][col2];
        
        return s4 + s1 - s2 - s3;
    }
    
protected:
    vector<vector<int>> data;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class Solution {
public:
    void setRow(vector<vector<int>>& matrix, int n, int k)
    {
        for(int i=1; i<n; ++i)
        {
            matrix[k][i] = 0;
        }
    }
    
    void setCol(vector<vector<int>>& matrix, int m, int k)
    {
        for(int i=1; i<m; ++i)
        {
            matrix[i][k] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m,n;
        m = matrix.size();
        
        if(m > 0)
        {
            n = matrix[0].size();
        }
        else
        {
            return;
        }
        
        bool firstRow, firstCol;
        firstRow = firstCol = false;
        
        for(int i=0; i<m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                firstRow = true;
                break;
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                setRow(matrix, n, i);
            }
        }
        
        for(int i=1; i<n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                setCol(matrix, m, i);
            }
        }
        
        if(firstRow)
        {
            for(int i=0; i<n; ++i)
            {
                matrix[0][i] = 0;
            }
        }
        
        if(firstCol)
        {
            for(int i=0; i<m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
};
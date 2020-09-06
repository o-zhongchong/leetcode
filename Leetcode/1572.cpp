class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int x = mat.size();
        
        if(x <= 0)
        {
            return 0;
        }
        
        int y = mat[0].size();
        int sum = 0;
        
        for(int i=0; i<x && i<y; ++i)
        {
            sum += mat[i][i];
        }
        
        for(int i=0; i<x && i<y; ++i)
        {
            sum += mat[x-1-i][i];
        }
        
        if(x & 1)
        {
            sum -= mat[x/2][x/2];
        }
        
        return sum;
    }
};
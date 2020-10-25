class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n <= 0)
        {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int up, down, left, right, val;
        up = left = 0;
        down = right = n - 1;
        val = 1;
        
        while(true)
        {
            for(int j = left; j <= right; ++j)
            {
                ret[up][j] = val++;
            }
            
            if(++up > down)
            {
                break;
            }
            
            for(int i = up; i <= down; ++i)
            {
                ret[i][right] = val++;
            }
            
            if(--right < left)
            {
                break;
            }
            
            for(int j = right; j >= left; --j)
            {
                ret[down][j] = val++;
            }
            
            if(--down < up)
            {
                break;
            }
            
            for(int i = down; i >= up; --i)
            {
                ret[i][left] = val++;
            }
            
            if(++left > right)
            {
                break;
            }
        }
        
        return ret;
    }
};
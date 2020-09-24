class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = m - 1;
        int y = m + n -2;
        
        return caculate(x,y);
    }
    
    int caculate(int x, int y)
    {
        double ret = 1;
        
        if(y - x < x)
        {
            x = y - x;
        }
        
        for(int i=1; i<=x; ++i)
        {
            ret = ret * (y-i+1) / i;
        }
        
        return ret;
    }
};
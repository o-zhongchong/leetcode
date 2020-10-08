class Solution {
public:
    int numSquares(int x) {
        if(x < 0)
        {
            return -1;
        }
        
        while( x != 0 && x % 4 == 0)
        {
            x = x / 4;
        }
        
        if(x % 8 == 7)
        {
            return 4;
        }
        
        for(int i=0; i*i <= x; ++i)
        {
            int j = sqrt(x-i*i);
            
            if(i*i + j*j == x)
            {
                return !!i + !!j;
            }
        }
        
        return 3;
    }
};
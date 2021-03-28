class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        long long m = abs(n);
        
        while(m)
        {
            if(m & 1)
            {
                ret *= x;
            }
            
            x = x * x;
            m >>= 1;
        }
        
        return n > 0 ? ret : 1 / ret;
    }
};
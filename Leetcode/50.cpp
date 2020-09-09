class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        
        int m = abs(n);
        double ret;
        
        if(m & 1)
        {
            ret = myPow(x, (m-1)/2);
            ret = ret * ret * x;
        }
        else
        {
            ret = myPow(x, m/2);
            ret = ret * ret;
        }
        
        if(n < 0)
        {
            return 1/ret;
        }
        
        return ret;
    }
};
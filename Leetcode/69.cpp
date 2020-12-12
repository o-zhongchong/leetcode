class Solution {
public:
    int mySqrt(int x) {
        long long ret = x;
        
        while(ret * ret > x)
        {
           ret = (ret + x / ret) / 2;
        }
        
        return ret;
    }
};
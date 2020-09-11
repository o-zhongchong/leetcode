class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1) 
           || (dividend == INT_MAX && divisor == 1))
        {
            return INT_MAX;
        }
        
        if(!dividend)
        {
            return 0;
        }
        
        int flag = sign(dividend) * sign(divisor);
        long long dividend_l = labs(dividend);
        long long divisor_l = labs(divisor);
        long long ret = 0;
        
        while(divisor_l <= dividend_l)
        {
            long temp = divisor_l;
            long weight = 1;
            
            while((temp << 1) <= dividend_l)
            {
                temp <<= 1;
                weight <<= 1;
            }
            
            dividend_l -= temp;
            ret += weight;
        }
        
        return ret * flag;
    }
    
    int sign(int x)
    {
        return x > 0 ? 1 : -1;
    }
};
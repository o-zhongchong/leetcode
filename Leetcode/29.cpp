class Solution {
public:
    int sign(int x)
    {
        return x > 0 ? 1 : -1;
    }
    
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1) 
           || (dividend == INT_MAX && divisor == 1))
        {
            return INT_MAX;
        }
        else if(!dividend)
        {
            return 0;
        }
        
        int flag = sign(dividend) * sign(divisor);
        long long dividend_l = labs(dividend);
        long long divisor_l = labs(divisor);
        long long res = 0;
        
        while(divisor_l <= dividend_l)
        {
            long tmp = divisor_l;
            long weight = 1;
            
            while((tmp << 1) <= dividend_l)
            {
                tmp <<= 1;
                weight <<= 1;
            }
            
            dividend_l -= tmp;
            res += weight;
        }
        
        return res * flag;
    }
};
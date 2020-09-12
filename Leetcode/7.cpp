class Solution {
public:
    int reverse(int x) {
        int flag = sign(x);
        long long x_l = labs(x);
        long long ret = 0;
        
        while(x_l)
        {
            ret *= 10;
            ret += (x_l % 10);
            x_l /= 10;
        }
        
        ret *= flag;
        
        if(ret < INT_MIN || ret > INT_MAX)
        {
            return 0;
        }
        
        return ret;
    }
    
    int sign(int x)
    {
        return x > 0 ? 1 : -1;
    }
};
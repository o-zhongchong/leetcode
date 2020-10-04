class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int x, y, ret = INT_MIN;
        x = y = 1;
        
        for(auto n : nums)
        {
            int p = get_max(n, n*x, n*y);
            int q = get_min(n, n*x, n*y);
            x = p;
            y = q;
            
            if(x > ret)
            {
                ret = x;
            }
        }
        
        return ret;
    }
    
    int get_max(int a, int b, int c)
    {
        if(a < b)
        {
            a = b;
        }
        
        return a > c ? a : c;
    }
    
    int get_min(int a, int b, int c)
    {
        if(a > b)
        {
            a = b;
        }
        
        return a < c ? a : c;
    }
};
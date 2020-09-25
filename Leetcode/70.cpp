class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        
        vector<int> ret(n+1,0);
        ret[1] = 1;
        ret[2] = 2;
        
        for(int i=3; i<=n; ++i)
        {
            ret[i] = ret[i-1] + ret[i-2];
        }
        
        return ret[n];
    }
};
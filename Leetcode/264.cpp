class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret(1,1);
        int i2, i3, i5;
        i2 = i3 = i5 = 0;
        
        for(int i=0; i<n; ++i)
        {
            int m2 = ret[i2] * 2;
            int m3 = ret[i3] * 3;
            int m5 = ret[i5] * 5;
            int mn = min(m2, min(m3,m5));
            
            if(mn == m2)
            {
                ++i2;
            }
            
            if(mn == m3)
            {
                ++i3;
            }
            
            if(mn == m5)
            {
                ++i5;
            }
            
            ret.push_back(mn);
        }
        
        return ret[n-1];
    }
};
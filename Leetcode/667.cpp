class Solution {
public:
    vector<int> constructArray(int n, int k) {
        if(n < 2 || k < 1 || k >= n)
        {
            return {};
        }
        
        vector<int> ret;
        int left=1, right=n;
        
        for(int i=0; i<k; ++i)
        {
            if(i & 1)
            {
                ret.push_back(right--);
            }
            else
            {
                ret.push_back(left++);
            }
        }
        
        for(int i=k; i<n; ++i)
        {
            if(k & 1)
            {
                ret.push_back(ret[i-1] + 1);
            }
            else
            {
                ret.push_back(ret[i-1] - 1);
            }
        }
        
        return ret;
    }
};
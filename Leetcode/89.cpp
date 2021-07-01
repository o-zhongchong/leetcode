class Solution {
public:
    vector<int> grayCode(int n) {
        int len = pow(2, n);
        vector<int> ret(len, 0);
        
        for(int i=0; i<len; ++i)
        {
            ret[i] = i ^ (i >> 1);
        }
        
        return ret;
    }
};
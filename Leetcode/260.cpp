class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitflag = 0;
        int mask = 1;
        
        for(auto n : nums)
        {
            bitflag ^= n;
        }
        
        while( (mask & bitflag) == 0)
        {
            mask = mask << 1;
        }
        
        vector<int> ret;
        ret.push_back(0);
        ret.push_back(0);
        
        for(auto n : nums)
        {
            if(n & mask)
            {
                ret[0] ^= n;
            }
            else
            {
                ret[1] ^= n; 
            }
        }
        
        return ret;
    }
};
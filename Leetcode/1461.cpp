class Solution {
public:
    int toInt(string s)
    {
        int ret = 0;
        
        for(auto &c : s)
        {
            ret <<= 1;
            ret |= (c - '0');
        }
        
        return ret;
    }
    
    bool hasAllCodes(string s, int k) {
        vector<bool> ret(pow(2, k), false);
        int len = s.size();
        
        for(int i=0; i<len; ++i)
        {
            if(i + k - 1 < len)
            {
                string bitString = s.substr(i,k);
                int n = toInt(bitString);
                ret[n] = true;
            }
        }
        
        for(int i=0; i<pow(2,k); ++i)
        {
            if(ret[i] == false)
            {
                return false;
            }
        }
        
        return true;
    }
};
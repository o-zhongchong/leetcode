class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int len = encoded.size();
        vector<int> ret(len+1, 0);
        int n_xor, except1_xor;
        n_xor = except1_xor = 0;
        
        for(int i=1; i<=len+1; ++i)
        {
            n_xor ^= i;
        }
        
        for(int i=0; i<len; ++i)
        {
            if(i & 1)
            {
                except1_xor ^= encoded[i];
            }
        }
        
        ret[0] = n_xor ^ except1_xor;
        
        for(int i=1; i<len+1; ++i)
        {
            ret[i] = encoded[i-1] ^ ret[i-1];
        }
        
        return ret;
    }
};
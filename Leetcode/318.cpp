class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ret = 0;
        vector<int> mask(len, 0);
        
        for(int i=0; i<len; ++i)
        {
            for(auto c:words[i])
            {
                mask[i] |= 1<<(c-'a');
            }
        }
        
        for(int i=1; i<len; ++i)
        {
            for(int j=0;j<i;++j)
            {
                if( (mask[i] & mask[j]) == 0)
                {
                    ret = max(ret, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ret;
    }
};
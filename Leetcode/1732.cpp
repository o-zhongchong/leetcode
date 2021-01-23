class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0, cur = 0;
        int len = gain.size();
        
        for(int i=0; i<len; ++i)
        {
            cur += gain[i];
            ret = max(ret, cur);
        }
        
        return ret;
    }
};
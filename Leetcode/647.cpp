class Solution {
public:
    int count(string& s, int i, int j, int& ret)
    {
        int len = s.size();
        
        while(i >= 0 && j < len && s[i] == s[j])
        {
            --i;
            ++j;
            ++ret;
        }
        
        return 0;
    }
    
    int countSubstrings(string s) {
        int ret = 0;
        int len = s.size();
        
        for(int i=0; i<len; ++i)
        {
            count(s, i, i, ret);
            count(s, i, i+1, ret);
        }
        
        return ret;
    }
};
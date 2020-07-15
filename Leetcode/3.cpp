class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.empty() )
            return 0;
        
        int len = s.size();
        int left = -1;
        unordered_map<int,int> m;
        int ret = 1;
        
        for(int i=0; i<len; ++i)
        {
            if(m.count(s[i]) && m[s[i]] > left )
                left = m[s[i]];
            m[s[i]] = i;
            ret=max(ret, i-left);
        }
        
        return ret;
    }
};
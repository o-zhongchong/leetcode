class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int ret = 0, start = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(s[i] == ' ')
            {
                if(i - start > 0)
                {
                    ++ret;
                }
                
                start = i + 1;
            }
        }
        
        if(len - start > 0)
        {
            ++ret;
        }
        
        return ret;
    }
};
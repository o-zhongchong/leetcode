class Solution {
public:
    int countBinarySubstrings(string s) {
        int len = s.size();
        int ret = 0;
        int index = s.find("01");
        
        while(index != s.npos)
        {
            ++ret;
            int i= index;
            int j = index + 1;
            
            while(i-1 >= 0 && j+1 < len && s[i-1] == s[i] && s[j+1] == s[j])
            {
                --i;
                ++j;
                ++ret;
            }
            
            index = s.find("01", index+2);
        }
        
        index = s.find("10");
        
        while(index != s.npos)
        {
            ++ret;
            int i= index;
            int j = index + 1;
            
            while(i-1 >= 0 && j+1 < len && s[i-1] == s[i] && s[j+1] == s[j])
            {
                --i;
                ++j;
                ++ret;
            }
            
            index = s.find("10", index+2);
        }
        
        return ret;
    }
};
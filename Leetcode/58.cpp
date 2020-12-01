class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int cnt = 0;
        int i = len - 1;
        
        while(s[i] == ' ')
        {
            --i;
        }
        
        for(; i >= 0; --i)
        {
            if(s[i] == ' ')
            {
                return cnt;
            }
            else
            {
                ++cnt;
            }
        }
        
        return cnt;
    }
};
class Solution {
public:
    int helper(string &s, char c)
    {
        int cnt = 0;
        int len = s.size();
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(s[i] == c)
            {
                ++j;
                cnt = max(cnt, j);
            }
            else
            {
                j = 0;
            }
        }
        
        return cnt;
    }
    
    bool checkZeroOnes(string s) {
        int len1 = helper(s, '0');
        int len2 = helper(s, '1');
        return len2 > len1;
    }
};
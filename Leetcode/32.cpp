class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int ret = 0;
        
        for(int i=0, j=0, cnt=0; i<len; ++i)
        {
            if(s[i] == '(')
            {
                ++cnt;
            }
            else if(s[i] == ')')
            {
                --cnt;
            }
            
            if(cnt == 0)
            {
                ret = max(ret, i-j+1);
            }
            else if(cnt < 0)
            {
                j = i + 1;
                cnt = 0;
            }
        }
        
        for(int i=len-1, j=len-1, cnt=0; i>=0; --i)
        {
            if(s[i] == ')')
            {
                ++cnt;
            }
            else if(s[i] == '(')
            {
                --cnt;
            }
            
            if(cnt == 0)
            {
                ret = max(ret, j-i+1);
            }
            else if(cnt < 0)
            {
                j = i - 1;
                cnt = 0;
            }
        }
        
        return ret;
    }
};
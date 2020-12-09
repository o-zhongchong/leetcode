class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int len = s.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            s[i] == '(' ? ++left : ++right;
            
            if(left == right)
            {
                ret = max(ret, left*2);
            }
            else if(right > left)
            {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        for(int i=len-1; i>=0; --i)
        {
            s[i] == '(' ? ++left : ++right;
            
            if(left == right)
            {
                ret = max(ret, left*2);
            }
            else if(left > right)
            {
                left = right = 0;
            }
        }
        
        return ret;
    }
};
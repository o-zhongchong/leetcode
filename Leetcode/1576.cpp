class Solution {
public:
    string modifyString(string s) {
        int len = s.size();
        
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '?')
            {
                char c = 'a';
                
                while((i - 1 >= 0 && s[i-1] == c) || (i + 1 < len && s[i+1] == c))
                {
                    c = c + 1;
                }
                
                s[i] = c;
            }
        }
        
        return s;
    }
};
class Solution {
public:
    int reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        
        return 0;
    }
    
    string reverseWords(string s) {
        int len = s.size();
        int i=0, j=0;
        
        for(i = 1; i < len; ++i)
        {
            if(s[i] == ' ' && s[i-1] == ' ')
            {
                s.erase(i-1, 1);
                --i;
                --len;
            }
        }
        
        if(!s.empty() && s[0] == ' ')
        {
            s.erase(0,1);
        }
        
        if(!s.empty() && s[s.size()-1] == ' ')
        {
            s.erase(s.size()-1,1);
        }
        
        len = s.size();
        
        for(i=0, j=0; j<len; ++j)
        {
            if(s[j] == ' ')
            {
                if(i < j)
                {
                    reverse(s, i, j-1);
                }
                
                i = j+1;
            }
        }
        
        if(i < j)
        {
            reverse(s, i, j-1);
        }
        
        reverse(s, 0, len-1);
        
        return s;
    }
};
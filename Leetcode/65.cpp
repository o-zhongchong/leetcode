class Solution {
public:
    string strip(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != ' ' && s[j] != ' ')
            {
                break;
            }
            
            if(s[i] == ' ')
            {
                ++i;
            }
            
            if(s[j] == ' ')
            {
                --j;
            }
        }
        
        return s.substr(i, j - i + 1);
    }
    
    bool isNumber(string s) {
        int e = -1, d = -1;
        s = strip(s);
        int len = s.size();
        
        for(int i=0; i<len; ++i)
        {
            if(s[i] == 'e' && e == -1)
            {
                e = i;
                continue;
            }
            
            if(s[i] == '.' && d == -1)
            {
                d = i;
                continue;
            }
            
            if(s[i] == '+' || s[i] == '-')
            {
                if(i != e + 1)
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
            
            if(s[i] < '0' || s[i] > '9')
            {
                return false;
            }
        }
        
        if(d != -1)
        {
            if(d-1 >=0 && s[d-1] >= '0' && s[d-1] <= '9')
            {
                //nothing to do
            }
            else if(d+1 < len && s[d+1] >= '0' && s[d+1] <= '9')
            {
                //notiong to do
            }
            else
            {
                return false;
            }
        }
        
        if(e != -1)
        {
            if(e+1 < len && s[e+1] != '+' && s[e+1] != '-')
            {
                //notiong to do
            }
            else if(e+2 < len)
            {
                //notiong to do
            }
            else
            {
                return false;
            }
            
            if(e-1 >= 0 && s[e-1] != '+' && s[e-1] != '-')
            {
                //notiong to do
            }
            else
            {
                return false;
            }
        }
        
        if(d != -1 && e != -1 && d > e)
        {
            return false;
        }
        
        return true;
    }
};
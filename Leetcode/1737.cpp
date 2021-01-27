class Solution {
public:
    int convert1(string& a, string& b)
    {
        int ret = INT_MAX;
        
        for(int i=1; i<26; ++i)
        {
            int cnt = 0;
            char ch = 'a' + i;
            
            for(auto c : a)
            {
                if(c >= ch)
                {
                    ++cnt;
                }
            }
            
            for(auto c : b)
            {
                if(c < ch)
                {
                    ++cnt;
                }
            }
            
            ret = min(ret, cnt);
        }
        
        return ret;
    }
    
    int convert2(string& a, string& b)
    {
        char ch;
        int cnt = 0, ret = 0;
        
        for(auto c : a)
        {
            if(cnt == 0)
            {
                ++cnt;
                ch = c;
            }
            else if(cnt > 0 && ch == c)
            {
                ++cnt;
            }
            else if(cnt > 0 && ch != c)
            {
                --cnt;
            }
        }
        
        for(auto c : b)
        {
            if(cnt == 0)
            {
                ++cnt;
                ch = c;
            }
            else if(cnt > 0 && ch == c)
            {
                ++cnt;
            }
            else if(cnt > 0 && ch != c)
            {
                --cnt;
            }
        }
        
        for(auto c : a)
        {
            if(c != ch)
            {
                ++ret;
            }
        }
        
        for(auto c : b)
        {
            if(c != ch)
            {
                ++ret;
            }
        }
        
        return ret;
    }
    
    int minCharacters(string a, string b) {
        int ret = INT_MAX;
        ret = min(ret, convert1(a, b));
        ret = min(ret, convert1(b, a));
        ret = min(ret, convert2(a, b));
        return ret;
    }
};
class Solution {
public:
    int remove(string& s, string t, int c)
    {
        int len = s.size();
        int ret = 0, j = 0;
        
        for(int i=0; i<len; ++i)
        {
            s[j++] = s[i];
            
            if(j > 1 && s[j-2] == t[0] && s[j-1] == t[1])
            {
                j -= 2;
                ret += c;
            }
        }
        
        s.resize(j);
        return ret;
    }
    
    int maximumGain(string s, int x, int y) {
        string t1 = "ab", t2 = "ba";
        
        if(x < y)
        {
            swap(t1, t2);
            swap(x, y);
        }
        
        return remove(s, t1, x) + remove(s, t2, y);
    }
};
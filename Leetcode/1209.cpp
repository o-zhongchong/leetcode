class Solution {
public:
    string remove(string &s, int k)
    {
        int len = s.size();
        char c;
        int cnt = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(cnt == 0 || (cnt != 0 && s[i] != c))
            {
                c = s[i];
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
            
            if(cnt >= k)
            {
                return s.substr(0, i-k+1) + s.substr(i+1, len-i-1);
            }
        }
        
        return s;
    }
    
    string removeDuplicates(string s, int k) {
        string pre = s;
        string ret = remove(pre, k);
        
        while(ret.size() != pre.size())
        {
            pre = ret;
            ret = remove(ret, k);
        }
        
        return ret;
    }
};
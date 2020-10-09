class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if(m > n)
        {
            return false;
        }
        
        int p = 0;
        
        for(int i=0; i<n; ++i)
        {
            if(t[i] == s[p])
            {
                ++p;
            }
        }
        
        return p == m ? true : false;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        
        if(len2 == 0)
        {
            return 0;
        }
        
        if(len1 < len2)
        {
            return -1;
        }
        
        int** dfa = new int*[len2];
        
        for(int i = 0; i < len2; ++i)
        {
            dfa[i] = new int[256];
            memset(dfa[i], 0, 256*sizeof(int));
        }
        
        int x = 0;
        dfa[0][needle[0]] = 1;
        
        for(int i=1; i < len2; ++i)
        {
            for(int c=0; c<256; ++c)
            {
                if(c == (int)needle[i])
                {
                    dfa[i][c] = i + 1;
                }
                else
                {
                    dfa[i][c] = dfa[x][c];
                }
            }
            x = dfa[x][needle[i]];
        }
        
        for(int i=0, j=0; i<len1; ++i)
        {
            j = dfa[j][haystack[i]];
            
            if(j == len2)
            {
                return i - len2 + 1;
            }
        }
        
        return -1;
    }
};
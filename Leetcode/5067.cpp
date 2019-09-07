class Solution {
public:
    int countLetters(string S) {
        int ret = 0;
        
        if( S.empty() )
            return ret;
        
        int len = S.size();
        ret = len;
        
        for(int step=1; step <= len-1; ++step)
        {
            int start = 0;
            while( start + step < len)
            {
                char c = S[start];
                bool flag = true;
                
                for(int i=start+1; i<=start+step; ++i )
                {
                    if(S[i] != c)
                    {
                        flag = false;
                        start = i;
                        break;
                    }
                }
                
                if(flag)
                {
                    ++ret;
                    ++start;
                }
            }
        }
        return ret;
    }
};
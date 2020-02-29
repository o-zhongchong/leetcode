class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.size();
        string ret;
        
        for(int i=0; i<s_len; ++i)
        {
            int step = 1;
            while( i-step >=0 && i+step < s_len)
            {
                if(s[i-step] == s[i+step])
                    ++step;
                else
                    break;
            }
            
            string str = s.substr(i-step+1, 2*(step-1)+1 );
            if( str.size() > ret.size() )
                ret = str;
        }
        
        for(int i=0,j=1; i<s_len && j<s_len; ++i,++j)
        {
            if(s[i] != s[j])
                continue;
            
            int step = 1;
            while(i-step >=0 && j+step < s_len)
            {
                if(s[i-step] == s[j+step])
                    ++step;
                else
                    break;
            }
            
            string str = s.substr(i-step+1, 2*(step-1)+2 );
            if( str.size() > ret.size() )
                ret = str;
        }
        
        return ret;
    }
};
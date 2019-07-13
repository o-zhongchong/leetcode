class Solution {
public:
    int minAddToMakeValid(string S) {
        int ret = 0;
        int stack = 0;
        
        for( auto c: S)
        {
            if(c == '(' )
                ++stack;
            else if( c == ')' )
            {
                if( stack >= 1)
                    --stack;
                else
                    ++ret;
            }
            else
                return -1;
        }
        
        if( stack >= 0 )
            ret += stack;
        
        return ret;
    }
};
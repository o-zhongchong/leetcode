class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int sign = 1;
        int start,end;
        
        start = -1, end = -1;
        for(int i=0; i<len; ++i)
        {
            if(-1 == start)
            {
                if( str[i] == ' ' )
                    continue;
                
                if( str[i] == '+' )
                {
                    if( i+1 < len && str[i+1] >= '0' && str[i+1]<='9' )
                    {
                        sign = 1;
                        start = i+1;
                        i = i+1;
                    }
                    else
                        return 0;
                }
                else if( str[i] == '-')
                {
                    if(i+1 < len && str[i+1] >= '0' && str[i+1]<='9')
                    {
                        sign = -1;
                        start = i+1;
                        i = i+1;
                    }
                    else
                        return 0;
                }
                else if(str[i]>='0' && str[i]<='9')
                {
                    sign = 1;
                    start = i;
                }
                else
                    return 0;
            }
            else if( -1 != start)
            {
                if(-1 == end && str[i] >='0' && str[i] <= '9')
                    continue;
                else
                {
                    end = i-1;
                    break;
                }
            }
        }
        
        if(-1 != start && -1 == end)
            end = len - 1;
        
        if(-1 != start && -1 != end)
        {
            while(start != end && str[start] == '0')
                ++start;
            
            string sub_str = str.substr(start, end-start+1);
            if(sub_str.size() < 10 )
                return atoi(sub_str.c_str()) * sign;
            
            if( sub_str.size() == 10 
               && strcmp(sub_str.c_str(), "2147483648" ) < 0 )
            {
                return atoi(sub_str.c_str()) * sign;
            }
            
            if( -1 == sign)
                return -2147483648;
            else if( 1 == sign )
                return 2147483647;
        }
        
        return 0;
    }
};
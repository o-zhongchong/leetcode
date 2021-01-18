class Solution {
public:
    bool checkValidString(string s) {
        int low, high, len;
        low = high = 0;
        len = s.size();
        
        for(int i=0; i<len; ++i)
        {
            if(s[i] == '(')
            {
                ++low;
                ++high;
            }
            else if(s[i] == ')')
            {
                if(low > 0) 
                {
                    --low;
                }
                
                --high;
            }
            else if(s[i] == '*')
            {
                if(low > 0)
                {
                    --low;
                }
                
                ++high;
            }
            
            if(high < 0)
            {
                return false;
            }
        }
        
        return low == 0;
    }
};
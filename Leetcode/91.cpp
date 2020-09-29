class Solution {
public:
    int numDecodings(string s) {
        int dp1, dp2;
        int len = s.size();
        
        if(len  == 0)
        {
            return 0;
        }
        
        dp1 = 0;
        dp2 = -1;
        
        if(s[0] >= '1' && s[0] <= '9')
        {
            dp2 = 1;
        }
        
        for(int i=1; i<len; ++i)
        {
            int dp3 = -1;
            
            if(dp2 != -1 && s[i] >= '1' && s[i] <= '9')
            {
                if(dp2 == 0)
                {
                    dp3 = 1;
                }
                else
                {
                    dp3 = dp2;
                }
            }
            
            if(dp1 != -1 && s[i-1] != '0')
            {
                int x = atoi(s.substr(i-1, 2).c_str());

                if(x > 0 && x <= 26)
                {
                    if(dp1 == 0 && dp3 == -1)
                    {
                        dp3 = 1;
                    }
                    else if(dp1 == 0 && dp3 != -1)
                    {
                        ++dp3;
                    }
                    else if(dp1 > 0 && dp3 == -1)
                    {
                        dp3 = dp1;
                    }
                    else if(dp1 > 0 && dp3 != -1)
                    {
                        dp3 += dp1;
                    }
                }
            }
            
            dp1 = dp2;
            dp2 = dp3;
        }
        
        if(dp2 == -1)
        {
            return 0;
        }
        
        return dp2;
    }
};
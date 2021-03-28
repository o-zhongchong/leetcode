class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<=i; ++j)
            {
                if(s[j] == s[i] && (i - j <= 2 || dp[j+1][i-1]))
                {
                    dp[j][i] = true;
                    ++ret;
                }
            }
        }
        
        return ret;
    }
};

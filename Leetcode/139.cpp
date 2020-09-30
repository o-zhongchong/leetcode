class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myset;
        
        for(auto str : wordDict)
        {
            myset.insert(str);
        }
        
        int len = s.size();
        
        if(len <= 0)
        {
            return true;
        }
        
        vector<bool> dp(len, 0);
        
        if(myset.find(string(1, s[0])) != myset.end())
        {
            dp[0] = true;
        }
        
        for(int i=1; i<len; ++i)
        {
            if(myset.find(s.substr(0, i+1)) != myset.end())
            {
                dp[i] = true;
                continue;
            }
            
            for(int j=0; j<i; ++j)
            {
                if(dp[j] && myset.find(s.substr(j+1, i-j)) != myset.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len-1];
    }
};
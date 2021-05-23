class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        vector<vector<string>> dp(1<<n, vector<string>(n, ""));
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i != j)
                {
                    int len1 = words[i].size();
                    int len2 = words[j].size();
                    
                    for(int k=min(len1, len2); k>0; --k)
                    {
                        if(words[i].substr(len1 - k) == words[j].substr(0, k))
                        {
                            overlap[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            dp[1<<i][i] = words[i];
        }
        
        for(int i=1; i < (1<<n); ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i & (1<<j))
                {
                    for(int k=0; k<n; ++k)
                    {
                        if(k != j && (i & (1<<k)))
                        {
                            string t = dp[i^(1<<j)][k] + words[j].substr(overlap[k][j]);
                            
                            if(dp[i][j].empty() || dp[i][j].size() > t.size())
                            {
                                dp[i][j] = t;
                            }
                        }
                    }
                }
            }
        }
        
        int last = (1<<n) - 1;
        string ret = dp[last][0];
        
        for(int j=1; j<n; ++j)
        {
            if(dp[last][j].size() < ret.size())
            {
                ret = dp[last][j];
            }
        }
        
        return ret;
    }
};
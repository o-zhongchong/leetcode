class Solution {
public:
    bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())
        {
            return 0;
        }
        
        int len = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(len, 1);
        int ret = 1;
        
        for(int i=1; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};
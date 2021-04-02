class Solution {
public:
    void count(string &str, int &c0, int &c1)
    {
        c0 = c1 = 0;
        
        for(auto &c: str)
        {
            if(c == '0') ++c0;
            if(c == '1') ++c1;
        }
        
        return;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<len; ++i)
        {
            int c1, c2;
            count(strs[i], c1, c2);
            
            for(int j=m; j>=c1; --j)
            {
                for(int k=n; k>=c2; --k)
                {
                    dp[j][k] = max(dp[j][k], dp[j-c1][k-c2] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
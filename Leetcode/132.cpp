class Solution {
public:
    void getPalindrome(const string &s, vector<vector<bool>> &p)
    {
        int len = s.size();
        for(int i=0; i<len; ++i) {
            int j,k;
            j = k = i;
            p[j][k] = true;
            while(j-1>=0 && k+1<len && s[j-1]==s[k+1]) {
                --j;++k;
                p[j][k] = true;
            }
        }
        for(int i=0; i<len-1; ++i) {
            int j,k;
            j=i;k=i+1;
            if(s[j]==s[k]) {
                p[j][k] = true;
                while(j-1>=0 && k+1<len && s[j-1]==s[k+1]) {
                    --j;++k;
                    p[j][k] = true;
                }
            }
        }
    }
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len+1, len);
        vector<vector<bool>> stat(len, vector<bool>(len,false));
        dp[0] = -1;
        getPalindrome(s,stat);
        for(int i=0; i<len; ++i) {
            for(int j=i; j>=0; --j) {
                if( stat[j][i] ) {
                    dp[i+1] = min(dp[i+1], dp[j]+1);
                }
            }
        }
        return dp[len];
    }
};
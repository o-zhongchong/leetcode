class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len,false));
        vector<vector<string>> ret;
        for(int i=0; i<len; ++i) {
            for(int j=0; j<=i; ++j) {
                if(s[i] == s[j] && (i-j<=2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
            }
        }
        vector<string> t;
        dfs(s, 0, dp, t, ret);
        return ret;
    }
private:
    void dfs(string &s, int pos, vector<vector<bool>> &dp,
        vector<string> &t, vector<vector<string>> &ret) 
    {
        int len = s.size();
        if(pos == len) {
            ret.push_back(t);
            return;
        }
        for(int i=pos; i<len; ++i) {
            if(dp[pos][i]) {
                t.push_back(s.substr(pos,i-pos+1));
                dfs(s,i+1,dp,t,ret);
                t.pop_back();
            }
        }
    }
};
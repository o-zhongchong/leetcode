class Solution {
public:
    int getLCS(string &s1, string &s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for(int i=0; i<len1; ++i)
        {
            for(int j=0; j<len2; ++j)
            {
                if(s1[i] == s2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[len1][len2];
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int lcs = getLCS(word1, word2);
        
        return len1 + len2 - 2 * lcs;
    }
};
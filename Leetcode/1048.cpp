class Solution {
public:
    bool isPredecessor(string &s1, string &s2)
    {
        if(s1.size() + 1 != s2.size())
        {
            return false;
        }
        
        int len = s1.size();
        
        for(int i=0; i<len; ++i)
        {
            if(s1[i] != s2[i])
            {
                string s3 = s2.substr(0,i) + s2.substr(i+1, len+1);
                
                if(s1 == s3)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        string s3 = s2.substr(0, len);
        
        if(s1 == s3)
        {
            return true;
        }
        
        return false;
    }
    
    static bool comp(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        vector<int> dp(len, 1);
        int ret = 0;
        sort(words.begin(), words.end(), comp);
        
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(isPredecessor(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};
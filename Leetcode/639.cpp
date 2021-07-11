class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<long long> dp(len+1, 0);
        unordered_map<string, int> m;
        int M = 1e9 + 7;
        int ret = 0;
        
        for(int i=1; i<10; ++i) {
            string s1(1, '0' + i);
            m[s1] = 1;
        }
        
        for(int i=0; i<10; ++i) {
            string s1 = "1" + string(1, '0' + i);
            m[s1] = 1;
        }
        
        for(int i=0; i<7; ++i) {
            string s1 = "2" + string(1, '0' + i);
            m[s1] = 1;
        }
        
        for(int i=0; i<10; ++i) {
            string s1 = "*" + string(1, '0' + i);
            
            if(i >= 0 && i < 7) {
                m[s1] = 2;
            }
            
            if(i >= 7 && i < 10) {
                m[s1] = 1;
            }
        }
        
        m["*"] = 9;
        m["**"] = 15;
        m["1*"] = 9;
        m["2*"] = 6;
        dp[0] = 1;
        
        for(int i=0; i<len; ++i)
        {
            string s1;
            s1 = s.substr(i, 1);
            if(m.count(s1)) dp[i+1] += dp[i] * m[s1];
            
            if(i > 0) {
                s1 = s.substr(i-1, 2);
                if(m.count(s1)) dp[i+1] += dp[i-1] * m[s1];
            }
            
            dp[i+1] %= M;
        }
        
        return dp[len];
    }
};
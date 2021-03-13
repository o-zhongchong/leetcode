class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ret = 0;
        long long M = 1e9 + 7;
        unordered_map<int,long long> dp;
        int len = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<len; ++i)
        {
            dp[arr[i]] = 1;
            
            for(int j=0; j<i; ++j)
            {
                if(arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j]))
                {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[i] / arr[j]] * dp[arr[j]]) % M;
                }
            }
        }
        
        for (auto &i : dp) 
        {
            ret = (ret + i.second) % M;
        }
        
        return ret;
    }
};
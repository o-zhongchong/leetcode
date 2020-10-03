class Solution {
public:
    unordered_map<int,int> dp;
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
        {
            return 0;
        }
        
        if(dp.count(amount))
        {
            return dp[amount];
        }
        
        int cnt = -1;
        
        for(auto c : coins)
        {
            if(amount >= c)
            {
                int r = coinChange(coins, amount-c);
                        
                if( r!= -1 && (cnt == -1 || r + 1 < cnt))
                {
                    cnt = r + 1;
                }
            }
        }
        
        dp[amount] = cnt;
        return cnt;
    }
};
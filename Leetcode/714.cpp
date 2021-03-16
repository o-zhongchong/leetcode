class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        int sell = 0;
        int hold = -prices[0];
        
        for(int i=1; i<len; ++i)
        {
            sell = max(sell, hold + prices[i] - fee);
            hold = max(hold, sell - prices[i]);
        }
        
        return max(sell, hold);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        
        int tmpMin = prices[0];
        int profit = 0;
        int len = prices.size();
        
        for(int i = 1; i < len; ++i)
        {
            profit = max(profit, prices[i] - tmpMin);
            tmpMin = min(tmpMin, prices[i]);
        }
        
        return profit;
    }
};
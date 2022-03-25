class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int len = costs.size();
        int ans = 0;
        vector<int> refund(len);
        for(int i=0; i<len; ++i) {
            ans += costs[i][0];
            refund[i] = costs[i][1] - costs[i][0];
        }
        sort(refund.begin(), refund.end());
        for(int i=0; i<len/2; ++i) ans += refund[i];
        return ans;
    }
};
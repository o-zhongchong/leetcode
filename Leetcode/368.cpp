class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int,int>> dp(len);
        vector<int> ret;
        sort(nums.begin(), nums.end());
        int mx = 0, mx_idx = 0;
        for(int i=0; i<len; ++i) {
            for(int j=i; j>=0; --j) {
                if(nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                    if(dp[i].first > mx) {
                        mx = dp[i].first;
                        mx_idx = i;
                    }
                }
            }
        }
        for(int i=0; i<mx; ++i) {
            ret.push_back(nums[mx_idx]);
            mx_idx = dp[mx_idx].second;
        }
        return ret;
    }
};
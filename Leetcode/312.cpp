class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(len+2, vector<int>(len+2,0));
        for(int w=1; w<=len; ++w) {
            for(int i=1; i+w-1<=len; ++i) {
                for(int k=i,j=i+w-1; k<=j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + 
                        dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][len];
    }
};
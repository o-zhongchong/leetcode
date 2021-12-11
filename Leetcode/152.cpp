class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp1 = nums[0], dp2 = nums[0];
        int ret = nums[0];
        int len = nums.size();
        for(int i=1; i<len; ++i) {
            int t1 = nums[i] * dp1;
            int t2 = nums[i] * dp2;
            dp1 = max(max(t1, t2), nums[i]);
            dp2 = min(min(t1, t2), nums[i]);
            ret = max(ret, max(dp1, dp2));
        }
        return ret;
    }
};
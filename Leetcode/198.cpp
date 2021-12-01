class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp1(len, 0);
        vector<int> dp2(len, 0);
        for(int i=0; i<len; ++i) {
            if(i == 0) {
                dp1[i] = nums[i];
                continue;
            }
            dp1[i] = dp2[i-1] + nums[i];
            dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        return max(dp1[len-1], dp2[len-1]);
    }
};
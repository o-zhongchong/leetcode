class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum=nums[0], mx=nums[0];
        for(int i=1; i<len; ++i) {
            sum >= 0 ? sum += nums[i] : sum = nums[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};
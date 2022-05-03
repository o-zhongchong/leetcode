class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int start = -1, end = -2;
        int mx = nums[0], mn = nums[len-1];
        for(int i=1; i<len; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[len-1-i]);
            if(nums[i] < mx) end = i;
            if(nums[len-1-i] > mn) start = len-1-i;
        }
        return end - start + 1;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        int target = -x;
        for (auto n : nums) target += n;
        if (target == 0) return len;
        unordered_map<int,int> m;
        int sum = 0;
        int ans = INT_MIN;
        m[0] = -1;
        for (int i=0; i<len; ++i) {
            sum += nums[i];
            if (m.count(sum - target)) {
                ans = max(ans, i - m[sum - target]);
            }
            m[sum] = i;
        }
        return ans == INT_MIN ? -1 : len - ans;
    }
};
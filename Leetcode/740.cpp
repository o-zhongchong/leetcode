class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();
        map<int, int> m;
        int dp1=0, dp2=0, pre=-1;
        int t1, t2;
        for(auto n : nums) m[n] += n;
        for(auto n : m) {
            if(n.first == pre + 1) {
                t1 = n.second + dp2;
            } else {
                t1 = max(dp1, dp2) + n.second;
            }
            t2 = max(dp1, dp2);
            dp1 = t1;
            dp2 = t2;
            pre = n.first;
        }
        return max(dp1, dp2);
    }
};
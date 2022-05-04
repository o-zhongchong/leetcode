class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;
        for(auto n : nums) {
            ++m[n];
        }
        for(auto n : nums) {
            if(n == k-n) {
                if(m[n] > 1) {
                    int cnt = m[n] / 2;
                    ans += cnt;
                    m[n] -= cnt * 2;
                }
            } else {
                if(m[n] > 0 && m.count(k-n) && m[k-n] > 0) {
                    int cnt = min(m[n], m[k-n]);
                    ans += cnt;
                    m[n] -= cnt;
                    m[k-n] -= cnt;
                }
            }
        }
        return ans;
    }
};
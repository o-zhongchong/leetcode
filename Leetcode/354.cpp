class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for (int i=0; i<len; ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = (right - left) / 2 + left;
                if (dp[mid] < envelopes[i][1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left >= dp.size()) {
                dp.push_back(envelopes[i][1]);    
            } else {
                dp[left] = envelopes[i][1];
            }
        }
        return dp.size();
    }
};
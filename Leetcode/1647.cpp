class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        for (int i=1; i<26; ++i) {
            if (cnt[i] == 0) break;
            if (cnt[i] >= cnt[i-1]) {
                ans += cnt[i-1] > 0 ? cnt[i] - cnt[i-1] + 1 : cnt[i];
                if (cnt[i-1] > 0) {
                    cnt[i] = cnt[i-1] - 1;
                } else {
                    cnt[i] = 0;
                }
            }
        }
        return ans;
    }
};
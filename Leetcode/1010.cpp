class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size();
        vector<int> cnt(60, 0);
        int ret = 0;
        for(int i=0; i<len; ++i) {
            int p = (60 - time[i]%60) % 60;
            ret += cnt[p];
            ++cnt[time[i] % 60];
        }
        return ret;
    }
};
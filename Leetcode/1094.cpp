class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size();
        vector<int> cnt(1001,0);
        for(auto &t : trips) {
            cnt[t[1]] += t[0];
            cnt[t[2]] -= t[0];
        }
        for(int i=0, cur=0; i<=1000; ++i) {
            cur += cnt[i];
            if(cur > capacity) return false;
        }
        return true;
    }
};
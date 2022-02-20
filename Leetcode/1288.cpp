class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0]==b[0] && a[1]<b[1]);
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        int ans = 0;
        for(int i=1, j=0; i<len; ++i) {
            int ret = covered(intervals[j],intervals[i]);
            if(ret == 1 || ret == 2) ++ans;
            if(ret == 0 || ret == 2) j = i;
        }
        return len - ans;
    }
private:
    int covered(vector<int>& a, vector<int>& b) {
        if(a[0]<=b[0] && a[1]>=b[1]) return 1;
        if(a[0]>=b[0] && a[1]<=b[1]) return 2;
        return 0;
    }
};

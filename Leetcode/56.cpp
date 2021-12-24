class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int len = intervals.size();
        vector<vector<int>> ret;
        for(int i=0; i<len; ++i) {
            int sz = ret.size();
            if(ret.empty() || !isOverlap(ret[sz-1], intervals[i])) {
                ret.push_back(intervals[i]);
                continue;
            }
        }
        return ret;
    }
private:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
    int isOverlap(vector<int> &a, vector<int> &b) {
        if(max(a[0], b[0]) <= min(a[1], b[1])) {
            a[0] = min(a[0], b[0]);
            a[1] = max(a[1], b[1]);
            return 1;
        }
        return 0;
    }
};
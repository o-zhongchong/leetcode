class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            if(a[0] < b[0]) return true;
            if(a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        };
        sort(points.begin(), points.end(), cmp);
        int ret = 0;
        int len = points.size();
        for(int i=0; i<len; ++i) {
            if(i-1>=0 && !merge(points[i-1], points[i])) {
                ++ret;
            }
            if(i == len-1) ++ret;
        }
        return ret;
    }
private:
    int merge(vector<int> &a, vector<int> &b) {
        int start = max(a[0],b[0]);
        int end = min(a[1],b[1]);
        if(start <= end) {
            b[0] = start;
            b[1] = end;
            return 1;
        }
        return 0;
    }
};
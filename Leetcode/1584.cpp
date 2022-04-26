class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> ds(n, INT_MAX);
        for(int i=1; i<n; ++i) {
            ds[i] = dist(points[0], points[i]);
        }
        int ans = 0;
        for(int i=1; i<n; ++i) {
            int v = minElement(ds);
            if(v == -1) break;
            ans += ds[v];
            ds[v] = INT_MAX;
            for(int i=0; i<n; ++i) {
                if(ds[i] == INT_MAX) continue;
                ds[i] = min(ds[i], dist(points[v], points[i]));
            }
        }
        return ans;
    }
private:
    static int dist(const vector<int> &a, const vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    static int minElement(const vector<int> &nums) {
        int ans = -1, len = nums.size();
        for(int i=0; i<len; ++i) {
            if(ans == -1 || nums[i] < nums[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
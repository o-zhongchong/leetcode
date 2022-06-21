class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        auto cmp = [](const int& a, const int& b) {
            return a < b;
        };
        int len = heights.size();
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i=1; i<len; ++i) {
            if (heights[i] <= heights[i-1]) continue;
            int diff = heights[i] - heights[i-1];
            bricks -= diff;
            pq.push(diff);
            if (bricks >= 0) continue;
            if (ladders <= 0) {
                return i-1;
            } else {
                bricks += pq.top(); pq.pop();
                --ladders;
            }
        }
        return len-1;
    }
};
class Solution {
public:
    typedef pair<int,int> node;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        int len = points.size();
        auto cmp = [](const node &a, const node &b) {
            return a.first < b.first;
        };
        priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
        for(int i=0; i<len; ++i) {
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push(make_pair(dist, i));
            while(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            auto point = pq.top(); pq.pop();
            ret.push_back(points[point.second]);
        }
        return ret;
    }
};
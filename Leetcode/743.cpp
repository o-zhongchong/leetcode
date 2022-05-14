class Solution {
public:
    typedef pair<int,int> node;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<unordered_map<int,int>> edges(n+1);
        vector<int> dist(n+1, INT_MAX);
        for (auto time : times) {
            edges[time[0]][time[1]] = time[2];
        }
        auto cmp = [](const node& a, const node& b) {
            return a.second > b.second;
        };
        priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
        pq.push(make_pair(k, 0));
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            if (t.second >= dist[t.first]) continue;
            dist[t.first] = t.second;
            for (auto e : edges[t.first]) {
                auto p = make_pair(e.first, e.second + t.second);
                if (p.second < dist[e.first]) pq.push(p);
            }
        }
        int ans = 0;
        for (int i=1; i<=n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
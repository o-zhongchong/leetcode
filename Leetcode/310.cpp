class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        vector<int> ret;
        for(auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        for(int i=0; i<n; ++i) {
            if(graph[i].size() == 1) q.push(i);
        }
        while(n > 2) {
            int sz = q.size();
            n -= sz;
            for(int i=0; i<sz; ++i) {
                int node = q.front();
                q.pop();
                for(auto a: graph[node]) {
                    graph[a].erase(node);
                    if(graph[a].size() == 1) q.push(a);
                }
            }
        }
        while(!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> pre(n, set<int>());
        vector<vector<int>> next(n, vector<int>());
        vector<set<int>> parent(n, set<int>());
        for(auto e : edges) {
            pre[e[1]].insert(e[0]);
            next[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(pre[i].empty()) q.push(i);
        }
        while(!q.empty()) {
            int t = q.front(); q.pop();
            for(auto i : next[t]) {
                parent[i].insert(t);
                for(auto j : parent[t]) parent[i].insert(j);
                pre[i].erase(t);
                if(pre[i].empty()) q.push(i);
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; ++i) {
            vector<int> t;
            for(auto j : parent[i]) {
                t.push_back(j);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
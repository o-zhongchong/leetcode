class Solution {
public:
    vector<vector<int>> criticalConnections(int n, 
        vector<vector<int>>& connections) 
    {
        vector<vector<int>> g(n);
        for (auto& conn : connections) {
            g[conn[0]].push_back(conn[1]);
            g[conn[1]].push_back(conn[0]);
        }
        int cnt = 1;
        vector<int> dfn(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;
        dfs(g, 0, -1, cnt, dfn, low);
        for (auto& conn : connections) {
            int u, v;
            if (dfn[conn[0]] < dfn[conn[1]]) {
                u = conn[0];
                v = conn[1];
            } else {
                u = conn[1];
                v = conn[0];
            }
            if (low[v] > dfn[u]) {
                ans.push_back(conn);
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& g, int cur, int pre, int& cnt,
        vector<int>& dfn, vector<int>& low)
    {
        dfn[cur] = low[cur] = cnt++;
        for (auto& next : g[cur]) {
            if (dfn[next] == 0) {
                dfs(g, next, cur, cnt, dfn, low);
                low[cur] = min(low[cur], low[next]);
            } else if (dfn[next] != 0 && next != pre) {
                low[cur] = min(low[cur], dfn[next]);
            }
        }
    }
};
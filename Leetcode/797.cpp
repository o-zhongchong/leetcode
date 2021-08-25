class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int> &road, vector<vector<int>> &ret) {
        int n = graph.size();
        int cur = road.back();
        if(cur == n-1) {
            ret.push_back(road);
            return;
        }
        for(auto next : graph[cur]) {
            road.push_back(next);
            dfs(graph,road,ret);
            road.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ret;
        vector<int> road = {0};
        dfs(graph, road, ret);
        return ret;
    }
};
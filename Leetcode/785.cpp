class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> root(n, 0);
        for(int i=0; i<n; ++i) root[i] = i;
        for(int i=0; i<n; ++i) {
            if(graph[i].empty()) continue;
            int x = find(root, i);
            int y = find(root, graph[i][0]);
            if(x == y) return false;
            for(int j=1; j<graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if(x == parent) return false;
                if(y != parent) root[parent] = y;
            }
        }
        return true;
    }
private:
    int find(vector<int> &root, int x) {
        return x == root[x] ? x : root[x] = find(root, root[x]);
    }
};
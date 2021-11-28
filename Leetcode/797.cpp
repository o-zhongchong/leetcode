class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<bool> visited(len, false);
        vector<vector<int>> ret;
        vector<int> path;
        helper(graph, 0, visited, path, ret);
        return ret;
    }
private:
    void helper(vector<vector<int>>& graph, int pos, vector<bool> &visited,
                vector<int> &path, vector<vector<int>> &ret)
    {
        path.push_back(pos);
        visited[pos] = true;
        if(pos == graph.size()-1) {
            ret.push_back(path);
            path.pop_back();
            visited[pos] = false;
            return;
        }
        int len = graph[pos].size();
        for(int i=0; i<len; ++i) {
            int next = graph[pos][i];
            if(!visited[next]) {
                helper(graph, next, visited, path, ret);
            }
        }
        path.pop_back();
        visited[pos] = false;
        return;
    }
};
class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &graph, int cur, int pre, 
           vector<int> &dfn, vector<int> &low, vector<bool> &visited)
    {
        if(visited[cur] == true)
        {
            return low[cur];
        }
        
        visited[cur] = true;
        dfn[cur] = cur;
        low[cur] = cur;
        int len = graph[cur].size();
        sort(graph[cur].begin(), graph[cur].end());
        
        for(int i=0; i<len; ++i)
        {
            if(graph[cur][i] != pre)
            {
                int r = dfs(graph, graph[cur][i], cur, dfn, low, visited);
                low[cur] = min(r, low[cur]);
            }
        }
        
        return low[cur];
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        vector<int> dfn(n, 0);
        vector<int> low(n, 0);
        vector<bool> visited(n, false);
        vector<vector<int>> ret;
        
        for(auto &edge: connections)
        {
            sort(edge.begin(), edge.end());
            
            if(graph.count(edge[0]))
            {
                graph[edge[0]].push_back(edge[1]);
            }
            else
            {
                graph[edge[0]] = vector<int>{edge[1]};
            }
            
            if(graph.count(edge[1]))
            {
                graph[edge[1]].push_back(edge[0]);
            }
            else
            {
                graph[edge[1]] = vector<int>{edge[0]};
            }
        }
        
        dfs(graph, 0, 0, dfn, low, visited);
        
        for(auto &edge: connections)
        {
            if(low[edge[1]] > dfn[edge[0]])
            {
                ret.push_back(edge);
            }
        }
        
        return ret;
    }
};
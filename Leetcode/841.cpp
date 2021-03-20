class Solution {
public:
    int dfs(vector<vector<int>> &rooms, int start, vector<bool> &visited, int &ret)
    {
        int len = rooms[start].size();
        visited[start] = true;
        
        for(int i=0; !ret && i<len; ++i)
        {
            if(!visited[rooms[start][i]])
            {
                dfs(rooms, rooms[start][i], visited, ret);
            }
        }
        
        for(auto isVisited : visited)
        {
            if(!isVisited)
            {
                return -1;
            }
        }
        
        ret = true;
        return 0;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool> visited(len, false);
        int ret = false;
        dfs(rooms, 0, visited, ret);
        return ret;
    }
};
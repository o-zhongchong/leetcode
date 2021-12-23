class Solution {
public:
    vector<int> findOrder(int numCourses, 
        vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses);
        queue<int> q;
        vector<int> ret;
        for(auto &pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            ++in[pre[0]];
        }
        for(int i=0; i<numCourses; ++i) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int t = q.front(); q.pop();
            ret.push_back(t);
            for(auto i: graph[t]) {
                if(--in[i] == 0) q.push(i);
            }
        }
        if(ret.size() == numCourses) {
            return ret;
        }
        return {};
    }
};
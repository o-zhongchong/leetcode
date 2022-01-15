class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int,vector<int>> m;
        vector<bool> visited(len, false);
        queue<int> q({0});
        visited[0] = true;
        int step = 0;
        for(int i=0; i<len; ++i) {
            m[arr[i]].push_back(i);
        }
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; ++i) {
                int pos = q.front(); q.pop();
                if(pos == len-1) return step;
                if(pos-1 >= 0 && !visited[pos-1]) {
                    visited[pos-1] = true;
                    q.push(pos-1);
                }
                if(pos+1 < len && !visited[pos+1]) {
                    visited[pos+1] = true;
                    q.push(pos+1);
                }
                for(auto next : m[arr[pos]]) {
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                m.erase(arr[pos]);
            }
            ++step;
        }
        return -1;
    }
};
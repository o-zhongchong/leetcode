class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len, false);
        deque<int> q;
        visited[start] = true;
        q.push_back(start);
        while(!q.empty()) {
            int idx = q.front();
            q.pop_front();
            if(arr[idx] == 0) return true;
            int next = idx + arr[idx];
            if(next >= 0 && next < len && !visited[next]) {
                visited[next] = true;
                q.push_back(next);
            }
            next = idx - arr[idx];
            if(next >= 0 && next < len && !visited[next]) {
                visited[next] = true;
                q.push_back(next);
            }
        }
        return false;
    }
};
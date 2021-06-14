class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len, false);
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            visited[i] = true;
            
            if(arr[i] == 0)
            {
                return true;
            }
            
            int left = i + arr[i];
            int right = i - arr[i];
            
            if(left >= 0 && left < len && !visited[left])
            {
                q.push(left);
            }
            
            if(right >= 0 && right < len && !visited[right])
            {
                q.push(right);
            }
        }
        
        return false;
    }
};
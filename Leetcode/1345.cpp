class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        vector<bool> visited(len, false);
        queue<int> q({0});
        unordered_map<int,vector<int>> m;
        int cnt = 0;
        visited[0] = true;
        
        for(int i=0; i<len; ++i)
        {
            m[arr[i]].push_back(i);
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int pos = q.front();
                q.pop();
                
                if(pos == len-1)
                {
                    return cnt;
                }
                
                if(pos - 1 >= 0 && !visited[pos-1])
                {
                    visited[pos-1] = true;
                    q.push(pos-1);
                }
                
                if(pos + 1 < len && !visited[pos+1])
                {
                    visited[pos+1] = true;
                    q.push(pos+1);
                }
                
                for(auto j : m[arr[pos]])
                {
                    if(j != pos && !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                
                m.erase(arr[pos]);
            }
            
            ++cnt;
        }
        
        return -1;
    }
};
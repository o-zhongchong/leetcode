class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back(vector<int>{target, 0});
        int len = stations.size();
        priority_queue<int> pq;
        int cur = startFuel;
        int cnt = 0;
        
        if(startFuel >= target)
        {
            return 0;
        }
        
        for(int i=0; i<len; ++i)
        {
            while(cur < stations[i][0] && !pq.empty())
            {
                cur += pq.top();
                pq.pop();
                ++cnt;
            }
            
            if(cur < stations[i][0])
            {
                return -1;
            }
            
            if(cur >= target)
            {
                return cnt;
            }
            
            if(stations[i][1] > 0)
            {
                pq.push(stations[i][1]);
            }
        }
        
        return -1;
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int len = customers.size();
        double avg_wait_time;
        long long nowtime = 0, total_wait_time = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(customers[i][0] > nowtime)
            {
                nowtime = customers[i][0];
            }
            
            nowtime += customers[i][1];
            total_wait_time += (nowtime - customers[i][0]);
        }
        
        avg_wait_time = (double)total_wait_time / (double)len;
        return (long long)(avg_wait_time * 100000) / 100000.0;
    }
};
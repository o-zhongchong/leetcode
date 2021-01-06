class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        int start = INT_MIN;
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(start < timeSeries[i])
            {
                start = timeSeries[i];
            }
            
            if(timeSeries[i] + duration > start)
            {
                ret += timeSeries[i] + duration - start;
                start = timeSeries[i] + duration;
            }
        }
        
        return ret;
    }
};
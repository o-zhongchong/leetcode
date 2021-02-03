class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int type_sz = candiesCount.size();
        int len = queries.size();
        vector<bool> ret(len, false);
        vector<long long> prefix_sum(type_sz+1, 0);
        
        for(int i=1; i<=type_sz; ++i)
        {
            prefix_sum[i] = prefix_sum[i-1] + (long long)candiesCount[i-1];
            
        }
        
        for(int i=0; i<len; ++i)
        {
            int type = queries[i][0];
            long long max_num = (long long)(queries[i][1] + 1) * 
                                (long long)queries[i][2];
            
            if(max_num > prefix_sum[type] && queries[i][1] < prefix_sum[type+1])
            {
                ret[i] = true;
            }
        }
        
        return ret;
    }
};
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix_sum(len, 0);
        prefix_sum[0] = nums[0];
        long long cnt = 0;
        
        for(int i=1; i<len; ++i)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        
        for(int i=0, j=0, k=0; i < len-2; ++i)
        {
            while(j <= i || (j < len-1 &&
                             prefix_sum[j] - prefix_sum[i] < prefix_sum[i]))
            {
                ++j;
            }
            
            while(k < j || (k < len-1 && prefix_sum[k] - prefix_sum[i]
                             <= prefix_sum[len-1] - prefix_sum[k]))
            {
                ++k;
            }
            
            cnt = (cnt + k - j) % (int)(1e9 + 7);
        }
        
        return cnt;
    }
};
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return 0;
        }
        
        int len = nums.size();
        vector<int> dp(len, INT_MIN);
        deque<pair<int, int>> dq;
        dp[0] = nums[0];
        dq.push_back(make_pair(nums[0], 0));
        
        for(int i=1; i<len; ++i)
        {
            dp[i] = nums[i] + dq[0].first;
            dq.push_back(make_pair(dp[i], i));
            
            if(!dq.empty() && dq[0].second <= i - k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty() && dq[0].first < dp[i])
            {
                dq.pop_front();
            }
        }
        
        return dp[len-1];
    }
};
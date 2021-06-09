class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return 0;
        }
        
        int len = nums.size();
        vector<int> dp(len, INT_MIN);
        deque<int> dq;
        dp[0] = nums[0];
        dq.push_back(0);
        
        for(int i=1; i<len; ++i)
        {
            dp[i] = nums[i] + dp[dq.front()];
            
            while(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty() && dp[dq.back()] < dp[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return dp[len-1];
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        deque<int> dq;
        vector<int> ret;
        
        for(int i=0; i<k; ++i)
        {
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        for(int i=k; i<len; ++i)
        {
            ret.push_back(nums[dq.front()]);
            
            while(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        if(!dq.empty())
        {
            ret.push_back(nums[dq.front()]);
        }
        
        return ret;
    }
};
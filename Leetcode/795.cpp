class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int len = nums.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            priority_queue<int> pq;
            
            for(int j=i; j<len; ++j)
            {
                pq.push(nums[j]);
                
                if(pq.top() >= left && pq.top() <= right)
                {
                    ++ret;
                }
                else if(pq.top() > right)
                {
                    break;
                }
            }
        }
        
        return ret;
    }
};
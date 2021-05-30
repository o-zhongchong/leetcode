class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<vector<int>> bucket(10);
        int len = nums.size();
        int mod = 1;
        
        if(len < 2)
        {
            return 0;
        }
        
        int mx = nums[0];
        
        for(auto n : nums)
        {
            mx = max(mx, n);
        }
        
        int cnt = floor(log(mx) / log(10)) + 1;
        
        while(cnt--)
        {
            for(int i=0; i<len; ++i)
            {
                int pos = (nums[i] / mod) % 10;
                bucket[pos].push_back(nums[i]);
            }
            
            for(int i=0, j=0; i<10 && j<len; ++i)
            {
                for(auto n : bucket[i])
                {
                    nums[j++] = n;
                }
                
                bucket[i].clear();
            }
            
            mod *= 10;
        }
        
        int ret = nums[1] - nums[0];
        
        for(int i=2; i<len; ++i)
        {
            ret = max(ret, nums[i] - nums[i-1]);
        }
        
        return ret;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long long> postion, presum;
        int ret = INT_MAX;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] == 1)
            {
                postion.push_back(i);
            }
        }
        
        len = postion.size();
        presum.push_back(0);
        
        for(int i=0; i<len; ++i)
        {
            presum.push_back(presum[i] + postion[i]);
        }
        
        for(int i=k/2; i < len-(k-1)/2; i++)
        {
            int left = k/2*postion[i] - (presum[i] - presum[i-k/2]) - 
                       k/2*(k/2+1)/2;
            int right = presum[i+1+(k-1)/2] - presum[i+1] - 
                        (k-1)/2*postion[i] - (k-1)/2*((k-1)/2+1)/2;
            ret = min(ret, left+right);
        }
        
        return ret;
    }
};
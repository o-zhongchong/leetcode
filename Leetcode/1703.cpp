class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long long> postion, prefix;
        int ret = INT_MAX;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] == 1)
            {
                postion.push_back(i);
            }
        }
        
        len = postion.size();
        prefix.push_back(0);
        
        for(int i=0; i<len; ++i)
        {
            prefix.push_back(prefix[i] + postion[i]);
        }
        
        for(int i = k / 2; i < len - (k - 1) / 2; i++)
        {
            int left = k / 2 * postion[i] - (prefix[i] - prefix[i-k/2]) - 
                       k / 2 * (k / 2 + 1) / 2;
            int right = prefix[i + 1 + (k - 1) / 2] - prefix[i + 1] - 
                        (k - 1) / 2 * postion[i] -
                        (1 + (k - 1) / 2) * ((k - 1) / 2) / 2;
            ret = min(ret, left+right);
        }
        
        return ret;
    }
};
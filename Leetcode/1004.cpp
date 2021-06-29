class Solution {
public:
    int longestOnes(vector<int>& nums, int m) {
        int len = nums.size();
        int ret = 0;
        
        for(int i=0, j=0, k=0; i<len; ++i)
        {
            if(nums[i] == 0)
            {
                ++k;
            }
            
            while(k > m)
            {
                if(nums[j] == 0)
                {
                    --k;
                }
                
                ++j;
            }
            
            ret = max(ret, i-j+1);
        }
        
        return ret;
    }
};
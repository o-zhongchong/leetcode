class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> nums(len, 1);
        int ret = 0;
        
        for(int i=0; i<len-1; ++i)
        {
            if(ratings[i+1] > ratings[i] && nums[i+1] <= nums[i])
            {
                nums[i+1] = nums[i] + 1;
            }
        }
        
        for(int i=len-1; i>0; --i)
        {
            if(ratings[i-1] > ratings[i] && nums[i-1] <= nums[i])
            {
                nums[i-1] = nums[i] + 1;
            }
        }
        
        for(int i=0; i<len; ++i)
        {
            ret += nums[i];
        }
        
        return ret;
    }
};
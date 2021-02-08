class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int len = nums.size();
        int sum1, sum2, ret;
        ret=sum1 = sum2 = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] >= 0)
            {
                sum1 += nums[i];
                sum2 = min(0, sum2 + nums[i]);
            }
            else
            {
                sum1 = max(0, sum1 + nums[i]);
                sum2 += nums[i];
            }
            
            ret = max(ret, abs(sum1));
            ret = max(ret, abs(sum2));
        }
        
        return ret;
    }
};
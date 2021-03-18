class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int inc = 1, desc = 1;
        
        if(len <= 0)
        {
            return 0;
        }
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] > nums[i-1])
            {
                inc = desc + 1;
            }
            else if(nums[i] < nums[i-1])
            {
                desc = inc + 1;
            }
        }
        
        return max(inc, desc);
    }
};
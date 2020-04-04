class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        
        if( len < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        int ret = nums[1] - nums[0];

        for(int i=2; i<len; ++i)
        {
            int diff = nums[i] - nums[i-1];
            if(diff > ret)
                ret = diff;
        }
        
        return ret;
    }
};
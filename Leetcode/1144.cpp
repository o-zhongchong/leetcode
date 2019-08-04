class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        unsigned int len = nums.size();
        if (len == 1 || len == 0)
            return 0;

        int ret1 = 0;
        for (int i = 1; i < len; i = i + 2)
        {
            int tmp = 0;
            if ( i - 1 >= 0 &&  nums[i] >= nums[i - 1] )
                tmp = nums[i] - nums[i - 1] + 1;

            if (i + 1 < len && nums[i] >= nums[i + 1])
                tmp = max(tmp, nums[i] - nums[i + 1] + 1);
            ret1 += tmp;
        }

        int ret2 = 0;
        for (int i = 0; i < len; i = i + 2)
        {
            int tmp = 0;
            if (i - 1 >= 0 && nums[i] >= nums[i - 1])
                tmp = nums[i] - nums[i - 1] + 1;

            if (i + 1 < len && nums[i] >= nums[i + 1])
                tmp = max(tmp, nums[i] - nums[i + 1] + 1);
            ret2 += tmp;
        }

        return min(ret1, ret2);
    }
};
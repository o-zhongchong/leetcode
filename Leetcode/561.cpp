class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.size() & 1)
            return -1;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (unsigned int i = 0; i < nums.size(); i = i + 2)
            ret += nums[i];
        return ret;
    }
};
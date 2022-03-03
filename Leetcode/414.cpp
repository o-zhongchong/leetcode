class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first, second, third;
        if(nums.empty()) return 0;
        int len = nums.size();
        first = second = third = LONG_MIN;
        for(int i=0; i<len; ++i) {
            if(nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if(nums[i] > second && nums[i] < first) {
                third = second;
                second = nums[i];
            } else if(nums[i] > third && nums[i] < second) {
                third = nums[i];
            }
        }
        return third == LONG_MIN ? first : third;
    }
};
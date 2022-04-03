class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int len = nums.size();
        int i=len-2, j=len-1;
        while(i>=0 && nums[i] >= nums[i+1]) --i;
        if(i >= 0) {
            while(nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
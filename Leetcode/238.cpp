class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        int len = nums.size();
        vector<int> ret(len, 1);
        for(int i=1, j=1; i<len; ++i) {
            j *= nums[i-1];
            ret[i] *= j;
        }
        for(int i=len-2, j=1; i>=0; --i) {
            j *= nums[i+1];
            ret[i] *= j;
        }
        return ret;
    }
};
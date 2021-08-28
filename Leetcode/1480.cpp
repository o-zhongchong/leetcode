class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, 0);
        ret[0] = nums[0];
        for(int i=1; i<len; ++i) {
            ret[i] = ret[i-1] + nums[i];
        }
        return ret;
    }
};
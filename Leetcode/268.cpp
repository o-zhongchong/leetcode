class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int len = nums.size();
        
        for(int i = 0; i < len; ++i)
        {
            ret ^= (i+1) ^ nums[i];
        }
        
        return ret;
    }
};
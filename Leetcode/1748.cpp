class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(i - 1 >= 0 && nums[i-1] == nums[i])
            {
                continue;
            }
            
            if(i + 1 < len && nums[i+1] == nums[i])
            {
                continue;
            }
            
            ret += nums[i];
        }
        
        return ret;
    }
};
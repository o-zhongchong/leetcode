class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] == nums[i-1])
            {
                return nums[i];
            }
        }
        
        return nums[0];
    }
};
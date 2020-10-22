class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)
        {
            return false;
        }
        
        int maxJump = 0;
        
        for(int i=0; i<len && i <= maxJump; ++i)
        {
            if(nums[i] + i > maxJump)
            {
                maxJump = nums[i] + i;
            }
        }
        
        return maxJump >= len - 1 ? true : false;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] == nums[i-1])
            {
                ++cnt;
                
                if(cnt > 1)
                {
                    nums.erase(nums.begin() + i);
                    --len;
                    --i;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        
        return nums.size();
    }
};
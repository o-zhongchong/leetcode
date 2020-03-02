class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int red_pos = 0;
        int white_pos = len-1;
        
        for(int i=0; i<len;)
        {
            if(0 == nums[i])
            {
                if(i == red_pos)
                {
                    ++red_pos;
                    ++i;
                }
                else
                {
                    swap(nums[red_pos],nums[i]);
                    ++red_pos;
                }
            }
            else if(2 == nums[i])
            {
                if(i >= white_pos)
                    return;
                else
                {
                    swap(nums[white_pos],nums[i]);
                    --white_pos;
                }
            }
            else if(1 == nums[i])
                ++i;
            else
                return;
        }
    }
};
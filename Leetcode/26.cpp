class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <=1 )
            return len;
        
        for(int i=1; i<len; )
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase( nums.begin()+i );
                --len;
            }
            else
                ++i;
        }
        return len;
    }
};
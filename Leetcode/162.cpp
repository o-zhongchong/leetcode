class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] < nums[i-1])
            {
                return i-1;
            }
        }
        
        return len-1;
    }
};
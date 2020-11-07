class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        
        while(i < j)
        {
            int mid = i + (j - i)/2;
            
            if(target > nums[mid])
            {
                i = mid + 1;
            }
            else if(target < nums[mid])
            {
                j = mid;
            }
            else
            {
                return mid;
            }
        }
        
        return i;
    }
};
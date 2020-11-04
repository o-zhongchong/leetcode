class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        
        if(0 == len)
        {
            return {-1,-1};
        }
        
        int start = 0, end = len;
        int pos = -1;
        
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            
            if(target > nums[mid])
            {
                start = mid + 1;
            }
            else if(target < nums[mid])
            {
                end = mid;
            }
            else
            {
                pos = mid;
                break;
            }
        }
        
        if(-1 == pos)
        {
            return {-1, -1};
        }
        
        start = end = pos;
        
        while(start - 1 >= 0 && nums[start-1] == nums[start])
        {
            --start;
        }
        
        while(end + 1 < len && nums[end+1] == nums[end])
        {
            ++end;
        }
        
        return {start,end};
    }
};
class Solution {
public:
    int bsearch(vector<int>& nums, int i, int j, int target)
    {
        while(i < j)
        {
            int mid = i + (j - i)/2;
            
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return -1;
        }
        
        int pivot = 0;
        int len = nums.size();
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] < nums[i-1])
            {
                pivot = i;
                break;
            }
        }
        
        if(pivot == 0)
        {
            return bsearch(nums, 0, len, target);
        }

        int ret = bsearch(nums, 0, pivot, target);
        
        if(ret == -1)
        {
            ret = bsearch(nums, pivot, len, target);
        }
        
        return ret;
    }
};
class Solution {
public:
    int search1(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return left;
    }
    
    int search2(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return left - 1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int right = search1(nums, target);
        int left = search2(nums, target);
        
        cout<<left<<" "<<right<<endl;
        
        if(left + 1 < len && right - 1 >= 0 && left + 1 <= right - 1)
        {
            return {left + 1, right - 1};
        }
        
        return {-1, -1};
    }
};
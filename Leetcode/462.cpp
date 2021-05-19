class Solution {
public:
    int getK(vector<int> &nums, int left, int right, int k)
    {
        int pivot = nums[left];
        int l = left;
        int r = right;
        
        while(l < r)
        {
            while(l < r && nums[r] >= pivot)
            {
                --r;
            }
            
            swap(nums[l], nums[r]);
            
            while(l < r && nums[l] < pivot)
            {
                ++l;
            }
            
            swap(nums[l], nums[r]);
        }
        
        nums[l] = pivot;
        
        if(l > k)
        {
            getK(nums, left, l-1, k);
        }
        else if(l < k)
        {
            getK(nums, l+1, right, k);
        }
        
        return 0;
    }
    
    int minMoves2(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int len = nums.size();
        int k = (len - 1) / 2;
        int ret = 0;
        getK(nums, 0, len-1, k);
        
        for(auto n : nums)
        {
            ret += abs(n - nums[k]);
        }
        
        return ret;
    }
};
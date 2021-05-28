class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> myset;
        int len = nums.size();
        int ret = 0, sum = 0;
        int left = 0, right = 0;
        
        while(right < len)
        {
            if(myset.count(nums[right]))
            {
                sum -= nums[left];
                myset.erase(nums[left]);
                ++left;
            }
            else
            {
                sum += nums[right];
                myset.insert(nums[right]);
                ++right;
            }
            
            ret = max(ret, sum);
        }
        
        return ret;
    }
};
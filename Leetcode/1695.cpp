class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> myset;
        int ret = 0;
        
        for(int i=0, j=0, win=0; i<len; ++i)
        {
            while(myset.find(nums[i]) != myset.end())
            {
                myset.erase(nums[j]);
                win -= nums[j];
                ++j;
            }
            
            myset.insert(nums[i]);
            win += nums[i];
            ret = max(ret, win);
        }
        
        return ret;
    }
};
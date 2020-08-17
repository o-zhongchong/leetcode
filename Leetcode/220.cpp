class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        
        if(len < 2 || k <= 0 || t < 0)
        {
            return false;
        }
        
        multiset<long long> myset;
        int j = 0;
        
        for(int i = 0; i < len; ++i)
        {
            if(i - j > k)
            {
                myset.erase((long long)nums[j++]);
            }
            
            auto s = myset.lower_bound((long long)nums[i] - t);
            
            if(s != myset.end() && abs((*s) - nums[i]) <= t)
            {
                return true;
            }
            
            myset.insert(nums[i]);
        }
        
        
        return false;
    }
    
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset;
        int len = nums.size();
        int pre, next;
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            myset.insert(nums[i]);
        }
        
        for(int i=0; i<len; ++i)
        {
            pre = next = nums[i];
            
            while(myset.count(pre-1))
            {
                myset.erase(pre-1);
                --pre;
            }
            
            while(myset.count(next+1))
            {
                myset.erase(next+1);
                ++next;
            }
            
            ret = max(ret, next-pre+1);
        }
        
        return ret;
    }
};
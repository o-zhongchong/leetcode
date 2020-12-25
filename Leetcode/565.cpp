class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            int cnt = 1;
            
            while(i != nums[i])
            {
                swap(nums[i], nums[nums[i]]);
                ++cnt;
            }
            
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
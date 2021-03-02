class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(2,0);
        
        for(int i=0; i<len; ++i)
        {
            while(nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] != i+1)
            {
                ret[0] = nums[i];
                ret[1] = i+1;
                break;
            }
        }
        
        return ret;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }
        
        int len = nums.size();
        vector<int> ret(len, 0);
        int product = 1;
        
        for(int i = 0; i < len; ++i)
        {
            if(i - 1 >= 0)
            {
                product *= nums[i-1];
            }
            
            ret[i] = product;
        }
        
        product = 1;
        
        for(int i = len - 1; i >= 0; --i)
        {
            if(i + 1 < len)
            {
                product *= nums[i + 1];
            }
            
            ret[i] *= product;
        }
        
        return ret;
    }
};
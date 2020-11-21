class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }
        
        int len = nums.size();
        vector<int> ret(len, 0);
        vector<int> arr1, arr2;
        arr1 = arr2 = ret;
        
        int product = 1;
        
        for(int i = 0; i < len; ++i)
        {
            if(i - 1 >= 0)
            {
                product *= nums[i-1];
            }
            
            arr1[i] = product;
        }
        
        product = 1;
        
        for(int i = len - 1; i >= 0; --i)
        {
            if(i + 1 < len)
            {
                product *= nums[i + 1];
            }
            
            arr2[i] = product;
        }
        
        for(int i = 0; i < len; ++i)
        {
            ret[i] = arr1[i] * arr2[i];
        }
        
        return ret;
    }
};
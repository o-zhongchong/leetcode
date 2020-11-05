class Solution {
public:
    int reverse(vector<int>& nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        
        while(i < j)
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
        
        return 0;
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> ret;
        int up = 1;
        
        for(int i=len-1; i>=0; --i)
        {
            up += digits[i];
            ret.push_back(up % 10);
            up = up / 10;
        }
        
        if(up)
        {
            ret.push_back(up);
        }
        
        reverse(ret);
        
        return ret;
    }
};
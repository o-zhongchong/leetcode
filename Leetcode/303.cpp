class NumArray {
public:
    vector<int> nums;
    vector<int> dp;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int len = nums.size();
        int sum = 0;
        
        for(int i=0; i<len; ++i)
        {
            sum += nums[i];
            dp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i < 0 || j >= nums.size())
        {
            return 0;
        }
        if(i == 0)
        {
            return dp[j];
        }
        
        return dp[j] - dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
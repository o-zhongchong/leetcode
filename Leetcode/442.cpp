class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;

        if( nums.empty() )
            return ret;
        
        int length = nums.size();
        for( int i=0; i<length; ++i)
        {
            int n = abs(nums[i]);
            if( nums[n-1] > 0 )
                nums[n-1] = -nums[n-1];
            else
                ret.push_back(n);
        }
        return ret;
    }
};
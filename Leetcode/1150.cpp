class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0, len = nums.size();
        for( auto &i: nums)
        {
            if( i == target)
                ++cnt;
        }
        if( cnt > len/2)
            return true;
        return false;
        
    }
};
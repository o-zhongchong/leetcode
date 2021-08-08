class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapNums;
        int len = nums.size();
        if(len < 2) return {};
        for(int i=0; i<len; ++i) {
            if(!mapNums.count(target - nums[i])) {
                mapNums[nums[i]] = i;
            }
            else {
                return {i,mapNums[target - nums[i]]};
            }
        }
        return {};
    }
};
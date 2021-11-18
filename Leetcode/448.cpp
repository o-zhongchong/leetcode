class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        for(int i=0; i<len; ++i) {
            while(nums[i] != i+1 && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i<len; ++i) {
            if(nums[i] != i+1) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
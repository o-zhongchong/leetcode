class Solution {
public:
    int find(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp;
        
        for(int i=0; i<len; ++i) {
            int pos = find(dp, nums[i]);
            
            if(pos >= 0 && pos < dp.size() && nums[i] < dp[pos]) {
                dp[pos] = nums[i];
            }
            
            if(pos >= dp.size()) {
                dp.push_back(nums[i]);
            }
        }
        
        return dp.size();
    }
};
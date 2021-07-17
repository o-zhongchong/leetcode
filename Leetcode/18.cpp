class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        
        for(int i=0; i<len-3; ++i) {
            for(int j=i+1; j<len-2; ++j) {
                int left = j + 1;
                int right = len - 1;
                
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum == target) {
                        vector<int> out={nums[i], nums[j], nums[left], nums[right]};
                        ret.insert(out);
                        --right;
                        ++left;
                    }
                    else if(sum > target) {
                        --right;
                    }
                    else if(sum < target) {
                        ++left;
                    }
                }
            }
        }
        
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
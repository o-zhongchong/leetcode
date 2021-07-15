class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        
        for(int i=0; i<len; ++i) {
            for(int j=i+1; j<len; ++j) {
                int sum = nums[i] + nums[j];
                int left = j + 1;
                int right = len;
                
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    
                    if(nums[mid] < sum) {
                        left = mid + 1;
                    }
                    else
                        right = mid;
                }
                
                ret += left - (j + 1);
            }
        }
        return ret;
    }
};
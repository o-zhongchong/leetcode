class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int len = nums.size();
        int ans = 0;
        for(int i=2,j=0; i<len; ++i) {
            if(nums[i] - nums[i-1] != nums[i-1] - nums[i-2]) {
                if(i - j > 2) {
                    ans += count(i-j-2);
                }
                j = i - 1;
            }
            if(i == len-1 && i - j + 1 > 2) {
                ans += count(i-j-1);
            }
        }
        return ans;
    }
private:
    int count(int n) {
        return (1+n)*n/2;
    }
};
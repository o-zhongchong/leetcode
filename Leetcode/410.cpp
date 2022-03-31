class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        long long left = 0, right = 0;
        for(int i=0; i<len; ++i) {
            left = max(left, (long long)nums[i]);
            right += nums[i];
        }
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(helper(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool helper(vector<int> &nums, long long s, int m) {
        long long sum = 0;
        int cnt = 1, len = nums.size();
        for(int i=0; i<len; ++i) {
            sum += (long long)nums[i];
            if(sum > s) {
                sum = (long long)nums[i];
                ++cnt;
                if(cnt > m) return false;
            }
        }
        return true;
    }
};
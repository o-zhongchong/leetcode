class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        bitset<10001> bits(1); 
        for(int i=0; i<len; ++i) {
            sum += nums[i];
        }
        if(sum & 1) return false;
        for(int i=0; i<len; ++i) {
            bits |= bits << nums[i];
        }
        return bits[sum/2];
    }
};
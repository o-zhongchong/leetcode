class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum=0, j=1;
        int len=nums.size();
        for(int i=0; i<len & k>0;) {
            if(j < nums[i]) {
                long long cnt = min(k, nums[i]-(int)j);
                sum += (2*j+cnt-1)*cnt/2;
                j += cnt;
                k -= cnt;
                continue;
            }
            if(j == nums[i]) ++j;
            ++i;
        }
        if(k > 0) sum += (j*2+k-1)*k/2;
        return sum;
    }
};
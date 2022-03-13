class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k <= 0) return nums.empty() ? -1 : nums[0];
        priority_queue<int,vector<int>> pq;
        int j = 0;
        while(k > 1 && j < nums.size()) {
            pq.push(nums[j++]);
            --k;
        }
        int ans = -1;
        if(!pq.empty()) ans = pq.top();
        if(k & 1)
            return j+1<nums.size() ? max(ans,nums[j+1]) : ans;
        if(pq.size() > 1)
            return ans;
        return -1;
    }
};
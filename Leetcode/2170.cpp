class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        int len = nums.size();
        int o1=0, o2=0;
        int e1=0, e2=0;
        m1[o1] = m1[o2] = m2[e1] = m2[e2] = 0;
        for(int i=0; i<len; i+=2) {
            ++m1[nums[i]];
            if(nums[i] != o1 && m1[nums[i]] > m1[o1]) {
                o2 = o1;
                o1 = nums[i];
            } else if(nums[i] != o1 && nums[i] != o2 && m1[nums[i]] > m1[o2]) {
                o2 = nums[i];
            }
        }
        for(int i=1; i<len; i+=2) {
            ++m2[nums[i]];
            if(nums[i] != e1 && m2[nums[i]] > m2[e1]) {
                e2 = e1;
                e1 = nums[i];
            } else if(nums[i] != e1 && nums[i] != e2 && m2[nums[i]] > m2[e2]) {
                e2 = nums[i];
            }
        }
        int ans = len;
        if(o1 != e1) {
            ans -= m1[o1] + m2[e1];
        } else {
            ans -= max(m1[o1] + m2[e2], m1[o2] + m2[e1]);
        }
        return ans;
    }
};
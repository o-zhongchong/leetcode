class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mx = INT_MIN;
        stack<int> st;
        for (int i=nums.size()-1; i>=0; --i) {
            if (nums[i] < mx) return true;
            while(!st.empty() && nums[i] > st.top()) {
                mx = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
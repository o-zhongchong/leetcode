class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int len = height.size();
        int ans = 0;
        for (int i=0; i<len; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int t = st.top(); st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[t];
                    int w = i - st.top() - 1;
                    ans += h * w;
                }
            }
            st.push(i);
        }
        return ans;
    }
};
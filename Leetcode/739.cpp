class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int len = t.size();
        vector<int> ret(len,0);
        stack<int> st;
        for(int i=0; i<len; ++i) {
            while(!st.empty() && t[i] > t[st.top()]) {
                ret[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};
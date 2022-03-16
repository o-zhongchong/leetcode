class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        stack<int> st;
        int len = pushed.size();
        int j = 0;
        for(int i=0; i<len; ++i) {
            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            if(pushed[i] == popped[j]) {
                ++j;
            } else {
                st.push(pushed[i]);
            }
        }
        while(j < len) {
            if(st.empty() || popped[j] != st.top()) return false;
            ++j; st.pop();
        }
        return true;
    }
};
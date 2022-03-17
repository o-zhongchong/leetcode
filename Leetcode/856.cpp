class Solution {
public:
    int scoreOfParentheses(string s) {
        int len = s.size();
        stack<int> st;
        int ans = 0;
        for(int i=0, j=0; i<len; ++i) {
            if(s[i]=='(') {
                st.push(0);
            } else if(s[i] == ')') {
                int t1 = st.top(); st.pop();
                t1 == 0 ? t1 = 1 : t1 *= 2;
                if(st.empty()) {
                    ans += t1;
                } else {
                    int t2 = st.top(); st.pop();
                    t2 += t1;
                    st.push(t2);
                }
            }
        }
        return ans;
    }
};
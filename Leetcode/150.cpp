class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto &str : tokens)
        {
            if(str == "+")
            {
                if(st.size() >= 2)
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 + x1);
                }
            }
            else if(str == "-")
            {
                if(st.size() >= 2)
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 - x1);
                }
            }
            else if(str == "*")
            {
                if(st.size() >= 2)
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 * x1);
                }
            }
            else if(str == "/")
            {
                if(st.size() >= 2)
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 / x1);
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        
        return st.top();
    }
};
class Solution {
public:
    void reverse(string &s)
    {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
        {
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    
    string removeDuplicates(string s) {
        stack<char> st;
        string ret;
        
        for(auto c : s)
        {
            if(!st.empty() && c == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        
        while(!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        
        reverse(ret);
        return ret;
    }
};
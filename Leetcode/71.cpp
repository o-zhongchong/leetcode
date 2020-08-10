class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty() || path[0]!='/')
            return "";
        
        stack<string> st;
        int start = 1;
        int len = path.size();
        
        if(path[len-1] != '/')
        {
            path.push_back('/');
            ++len;
        }
        
        for(int i=1; i<len; ++i)
        {
            if(path[i] == '/')
            {
                if(i == start)
                {
                    start = i + 1;
                    continue;
                }
                
                string f = path.substr(start, i - start);
                start = i + 1;
                
                if(f == ".")
                {
                    continue;
                }
                else if(f == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else
                {
                    st.push(f);
                }
            }
        }
        
        string ret;
        
        while(!st.empty())
        {
            string s = st.top();
            st.pop();
            ret = "/" + s + ret;
        }
        
        if(ret == "")
            ret = "/";
        
        return ret;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        stack<string> st;
        for(int i=0,j=0; i<len; ++i) {
            string f = "";
            if(path[i] == '/') {
                if(i-j > 0) f = path.substr(j, i-j);
                j = i + 1;
            } else if(path[i] != '/' && i==len-1) {
                if(len-j > 0) f = path.substr(j, len-j);
                j = i + 1;
            }
            if(f == "." || f == "") continue;
            if(f == "..") {
                if(!st.empty()) st.pop();
                continue;
            }
            st.push(f);
        }
        if(st.empty()) return "/";
        string ans = "";
        while(!st.empty()) {
            string t = st.top(); st.pop();
            ans = "/" + t + ans;
        }
        return ans;
    }
};
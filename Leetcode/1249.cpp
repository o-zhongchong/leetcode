class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.size();
        string ans = "";
        vector<int> st, del;
        for(int i=0; i<len; ++i) {
            if(s[i] == '(') {
                st.push_back(i);
            } else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop_back();
                } else {
                    del.push_back(i);
                }
            }
            while(i == len-1 && !st.empty()) {
                del.push_back(st.back());
                st.pop_back();
            }
        }
        sort(del.begin(), del.end());
        for(int i=0,j=0; i<len; ++i) {
            if(j<del.size() && del[j]==i) {
                ++j;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
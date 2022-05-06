class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(auto c : s) {
            if(st.empty() || st.back().first != c) {
                st.push_back(make_pair(c, 1));
                continue;
            }
            st.back().second += 1;
            if(st.back().second >= k) st.pop_back();
        }
        string ans = "";
        for(auto t : st) {
            ans.append(t.second, t.first);
        }
        return ans;
    }
};
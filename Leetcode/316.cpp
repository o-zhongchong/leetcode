class Solution {
public:
    string removeDuplicateLetters(string s) {
        int dict[26], visited[26];
        memset(dict, 0, sizeof(dict));
        memset(visited, 0, sizeof(visited));
        string ans = "";
        int len = s.size();
        for(auto c : s) ++dict[c-'a'];
        for(int i=0; i<len; ++i) {
            int idx = s[i] - 'a';
            --dict[idx];
            if(visited[idx]) continue;
            while(!ans.empty() && s[i] < ans.back() && dict[ans.back()-'a'] > 0) {
                visited[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[idx] = 1;
        }
        return ans;
    }
};
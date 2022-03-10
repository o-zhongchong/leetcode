class Solution {
public:
    int minSteps(string s, string t) {
        int dict[26], ans=0;
        memset(dict,0,sizeof(dict));
        for(auto c:s) ++dict[c-'a'];
        for(auto c:t) --dict[c-'a'];
        for(int i=0; i<26; ++i) {
            ans += abs(dict[i]);
        }
        return ans;
    }
};
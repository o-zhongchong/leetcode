class Solution {
public:
    int maxPower(string s) {
        int len = s.size();
        int mx = 1;
        for(int i=1, j=1; i<len; ++i) {
            if(s[i] == s[i-1]) {
                ++j;
                mx = max(mx, j);
            } else {
                j = 1;
            }
        }
        return mx;
    }
};
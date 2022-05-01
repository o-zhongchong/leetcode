class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i, j, cnt;
        i = s.size() - 1;
        j = t.size() - 1;
        while(i >= 0 || j >= 0) {
            cnt = 0;
            while(i >= 0 && (s[i] == '#' || cnt > 0)) {
                if(s[i] == '#') {
                    ++cnt;
                } else if(s[i] != '#' && cnt > 0) {
                    --cnt;
                }
                --i;
            }
            cnt = 0;
            while(j >= 0 && (t[j] == '#' || cnt > 0)) {
                if(t[j] == '#') {
                    ++cnt;
                } else if(t[j] != '#' && cnt > 0) {
                    --cnt;
                }
                --j;
            }
            if((i >= 0 && j < 0) || (i < 0 && j >= 0)) return false;
            if(i >= 0 && j >= 0 && s[i] == t[j]) {
                --i;
                --j;
            } else if(i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
        }
        if(i >= 0 || j >= 0) {
            return false;
        }
        return true;
    }
};
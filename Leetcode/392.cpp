class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int len1 = s.size();
        int len2 = t.size();
        for(int i=0, j=0; i<len2; ++i) {
            if(t[i] == s[j]) ++j;
            if(j == len1) return true;
        }
        return false;
    }
};
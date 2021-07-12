class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int len = s.size();
        unordered_map<char,char> m1, m2;
        
        for(int i=0; i<len; ++i) {
            if(m1.count(s[i])) {
                if(m1[s[i]] != t[i]) return false;
            }
            else {
                if(m2.count(t[i])) return false;
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        
        return true;
    }
};
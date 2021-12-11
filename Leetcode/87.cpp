class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(memo.count({s1, s2})) return memo[{s1, s2}];
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int len = s1.size(), m[26] = {0};
        for(int i=0; i<len; ++i) {
            ++m[s1[i] - 'a'];
            --m[s2[i] - 'a'];
        }
        for(int i=0; i<26; ++i) {
            if (m[i] != 0) return false;
        }
        for(int i=1; i<len; ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return memo[{s1,s2}] = true;
            }
            s21 = s2.substr(s1.size()-i);
            s22 = s2.substr(0, s1.size()-i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return memo[{s1,s2}] = true;
            }
        }
        return memo[{s1,s2}] = false;
    }
private:
    map<array<string, 2>, bool> memo;
};
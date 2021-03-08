class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
        {
            return 0;
        }
        
        string str = s;
        reverse(str.begin(), str.end());
        return str == s ? 1 : 2;
    }
};
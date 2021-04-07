class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'O', 'I', 'U'};
        int len = s.size();
        int cnt = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(i < len/2 && vowel.count(s[i]))
            {
                ++cnt;
            }
            
            if(i >= len/2 && vowel.count(s[i]))
            {
                --cnt;
            }
        }
        
        return cnt == 0;
    }
};
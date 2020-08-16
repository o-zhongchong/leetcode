class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        int count[26];
        
        for(int i = 0; i < 26; ++i)
        {
            count[i] = 0;
        }
        
        for( auto c : s)
        {
            int i = c - 'a';
            ++count[i];
        }
        
        for( auto c : t)
        {
            int i = c - 'a';
            --count[i];
        }
        
        for(int i = 0; i < 26; ++i)
        {
            if( count[i] )
                return false;
        }
        
        return true;
    }
};
class Solution {
public:
    int vowelsCounts(string s)
    {
        int cnt = 0;
        string str = "aeoiuAEIOU";
        
        for(auto c : s)
        {
            if(str.find(c) != string::npos)
            {
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    bool halvesAreAlike(string s) {
        int len = s.size();
        int cnt1 = vowelsCounts(s.substr(0, len/2));
        int cnt2 = vowelsCounts(s.substr(len/2, len/2));
        
        return cnt1 == cnt2;
    }
};
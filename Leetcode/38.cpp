class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
            return string("1");
        }
        
        string s1 = countAndSay(n-1);
        string s2;
        int cnt = 1;
        char c = s1[0];
        int len = s1.size();
        
        for(int j=1; j<len; ++j)
        {
            if(s1[j] == c)
            {
                ++cnt;
            }
            else
            {
                s2 += to_string(cnt) + c;
                c = s1[j];
                cnt = 1;
            }
        }
        
        s2 += to_string(cnt) + c;
        
        return s2;
    }
};
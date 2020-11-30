class Solution {
public:
    string filter(string s)
    {
        string t;
        
        for(auto c : s)
        {
            if(c >= 'a' && c <= 'z')
            {
                t.push_back(c);
            }
            else if(c >= 'A' && c <= 'Z')
            {
                t.push_back(c - 'A' + 'a');
            }
            else if(c >= '0' && c <= '9')
            {
                t.push_back(c);
            }
        }
        
        return t;
    }
    
    bool isPalindrome(string s) {
        if(s == "")
        {
            return true;
        }
        
        string t = filter(s);
        int i = 0;
        int j = t.size() - 1;
        
        while(i < j)
        {
            if(t[i] != t[j])
            {
                return false;
            }
            else
            {
                ++i;
                --j;
            }
        }
        
        return true;
    }
};
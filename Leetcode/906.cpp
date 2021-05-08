class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void helper(string str, long &left, long &right, int &cnt)
    {
        if(str.size() > 9)
        {
            return;
        }
        
        if(!str.empty() && str[0] != '0')
        {
            long num = stol(str);
            num *= num;
            
            if(num > right)
            {
                return;
            }
            
            if(num >= left)
            {
                if(isPalindrome( to_string(num) ))
                {
                    ++cnt;
                }
            }
        }
        
        for(char c='0'; c<='9'; ++c)
        {
            helper(string(1,c) + str + string(1,c), left, right, cnt);
        }
        
        return;
    }
    
    int superpalindromesInRange(string left, string right) {
        long L = stol(left);
        long R = stol(right);
        int cnt = 0;
        helper("", L, R, cnt);
        
        for(char c='0'; c<'9'; ++c)
        {
            helper(string(1,c), L, R, cnt);
        }
        
        return cnt;
    }
};
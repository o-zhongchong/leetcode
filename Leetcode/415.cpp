class Solution {
public:
    void reverse(string &s)
    {
        int i = 0, j = s.size() - 1;
        
        while(i < j)
        {
            swap(s[i],s[j]);
            ++i;
            --j;
        }
        
        return;
    }
    
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int upper = 0;
        string ret;
        
        for(int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; --i, --j)
        {
            int t1, t2;
            t1 = t2 = 0;
            
            if(i >= 0)
            {
                t1 = num1[i] - '0';
            }
            
            if(j >= 0)
            {
                t2 = num2[j] - '0';
            }
            
            int sum = t1 + t2 + upper;
            upper = sum / 10;
            ret.push_back('0' + (sum % 10));
        }
        
        if(upper)
        {
            ret.push_back('0' + (upper % 10));
        }
        
        reverse(ret);
        return ret;
    }
};
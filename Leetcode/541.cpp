class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        
        if(k < 0)
        {
            return s;
        }
        
        for(int i=0; i<len; i=i+k+k)
        {
            reverseSubStr(s, i, i+k-1);
        }
        
        return s;
    }
    
    int reverseSubStr(string& s, int start, int end)
    {
        int len = s.size();
        
        if(start < 0 || start >= len || end < 0)
        {
            return -1;
        }
        
        if(end >= len)
        {
            end = len -1;
        }
        
        while(start < end)
        {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        
        return 0;
    }
};
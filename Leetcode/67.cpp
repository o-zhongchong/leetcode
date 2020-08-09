class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int len = max(m,n);
        
        string x = a;
        string y = b;
        string ret;
        int c = 0;
        
        x.insert(0,len-m,'0');
        y.insert(0,len-n,'0');
        
        for(int i=0; i<len; ++i)
        {
            int sum = (x[len-i-1]-'0') + (y[len-i-1]-'0') + c;
            ret.insert(0,1,sum%2 + '0');
            c = sum/2;
        }
        
        if(c != 0)
            ret.insert(0,1,'1');
        
        return ret;
    }
};
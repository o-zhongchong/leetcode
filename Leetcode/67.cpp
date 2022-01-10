class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int len = max(m,n);
        a.insert(0, len-m, '0');
        b.insert(0, len-n, '0');
        string ret;
        for(int i=len-1,j=0; i>=0; --i) {
            int sum = (a[i]-'0')+(b[i]-'0')+j;
            j = sum/2;
            ret.insert(0,1,sum%2+'0');
            if(i==0 && j>0) ret.insert(0,1,'1'); 
        }
        return ret;
    }
};
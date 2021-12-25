class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int arg0=0, arg1=0, len=s.size();
        int ret = 0;
        for(int i=0; i<len; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                arg1 = arg1 * 10 + (int)(s[i] - '0');
            }
            if(s[i] == '+' || s[i] == '-' ||
               s[i] == '*' || s[i] == '/' ||
               i == len - 1) 
            {
                switch(op) {
                case '+':
                    arg0 += arg1; break;
                case '-':
                    arg0 -= arg1; break;
                case '*':
                    arg0 *= arg1; break;
                case '/':
                    arg0 /= arg1; break;
                }
                if(s[i] != '*' && s[i] != '/') {
                    ret += arg0;
                    arg0 = 0;
                }
                arg1 = 0;
                op = s[i];
            }
        }
        return ret;
    }
};
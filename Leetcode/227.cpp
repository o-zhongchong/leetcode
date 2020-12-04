class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        int num = 0, pre = 0, ret = 0;
        char op = '+';
        
        for(int i=0; i<len; ++i)
        {
            char c = s[i];
            
            if(c >= '0' && c <= '9')
            {
                num = c - '0' + num * 10;
            }
            
            if(c == '+' || c == '-' || c == '*' || c == '/' || i == len-1)
            {
                switch(op)
                {
                    case '+':pre += num; break;
                    case '-':pre -= num; break;
                    case '*':pre *= num; break;
                    case '/':pre /= num; break;
                }
                
                if(c == '+' || c == '-' || i == len - 1)
                {
                    ret += pre;
                    pre = 0;
                }
                
                op = c;
                num = 0;
            }
        }
        
        return ret;
    }
};
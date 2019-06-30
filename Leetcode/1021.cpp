#include <stack>

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> strStack;
        string resStr;
        
        for( int i = 0; i < S.size(); ++i )
        {
            if( S[i] == '(' )
            {
                strStack.push(i);
                continue;
            }
            else if( S[i] == ')' )
            {
                int index = strStack.top();
                strStack.pop();
                if( strStack.empty() && i - index > 1)
                {
                    resStr += S.substr(index + 1, i - index -1);
                }
            }
        }
        
        return resStr;
    }
};
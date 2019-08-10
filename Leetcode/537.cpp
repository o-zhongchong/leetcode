class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int p1, p2, p3, p4;
        
        if( parseStr(a,p1,p2) || parseStr(b,p3,p4) )
        {
            return string("error");
        }
        
        int ret1 = p1 * p3 - p2 * p4;
        int ret2 = p1 * p4 + p2 * p3;
        return to_string(ret1) + "+" + to_string(ret2) + "i";
    }
protected:
    int parseStr(string &s, int &x, int &y)
    {
        int index = s.find("+");
        string substr1, substr2;
        
        if( index != string::npos )
        {
            substr1 = s.substr(0, index);
            
            int len = s.size();
            if( index+1 < len && s.back() == 'i')
            {
                substr2 = s.substr(index+1, len-index-2);
            }
            else
                return -2;
        }
        else
            return -1;
        
        x = atoi(substr1.c_str());
        y = atoi(substr2.c_str());
        return 0;
    }
};
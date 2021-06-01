class Solution {
public:
    string maxValue(string n, int x) {
        if(n.empty())
        {
            return "";
        }
        
        int len = n.size();
        int pos = 0;
        
        if(n[0] == '-')
        {
            while(pos<len && n[pos]-'0' <= x)
            {
                ++pos;
            }
        }
        else
        {
            while(pos<len && n[pos]-'0' >= x)
            {
                ++pos;
            }
        }
        
        n.insert(pos, 1, '0' + x);
        return n;
    }
};
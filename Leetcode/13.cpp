class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r2i = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                        {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = s.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            int val = r2i[s[i]];
            
            if(i+1 < len && val < r2i[s[i+1]])
            {
                ret -= val;
            }
            else
            {
                ret += val;
            }
        }
        
        return ret;
    }
};
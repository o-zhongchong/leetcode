class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        int len = s.size();
        
        for(int i=0; i<len; ++i)
        {
            if(count.find(s[i])==count.end())
            {
                count[s[i]] = 1;
            }
            else
            {
                ++count[s[i]];
            }
        }
        
        for(int i=0; i<len; ++i)
        {
            if(count[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
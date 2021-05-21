class Solution {
public:
    bool isMatch(string &s1, string &s2)
    {
        unordered_map<char, char> mapping;
        unordered_map<char, char> r_mapping;
        
        if(s1.size() != s2.size())
        {
            return false;
        }
        
        int len = s1.size();
        
        for(int i=0; i<len; ++i)
        {
            if(mapping.count(s1[i]))
            {
                if(mapping[s1[i]] != s2[i])
                {
                    return false;
                }
            }
            else
            {
                if(r_mapping.count(s2[i]))
                {
                    return false;    
                }
                
                mapping[s1[i]] = s2[i];
                r_mapping[s2[i]] = s1[i];
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        
        for(auto &word : words)
        {
            if(isMatch(pattern, word))
            {
                ret.push_back(word);
            }
        }
        
        return ret;
    }
};
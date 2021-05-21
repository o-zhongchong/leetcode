class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)     {
        vector<string> ret;
        string p = helper(pattern);
        
        for(auto &word : words)
        {
            if(helper(word) == p)
            {
                ret.push_back(word);
            }
        }
        
        return ret;
    }
    
    string helper(string &s)
    {
        unordered_map<char, int> m;
        string ret = "";
        
        for(auto c : s)
        {
            if(!m.count(c))
            {
                m[c] = m.size();
            }
        }
        
        for(auto c : s)
        {
            ret.push_back('a' + m[c]);
        }
        
        return ret;
    }
};
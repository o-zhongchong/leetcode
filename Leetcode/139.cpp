class Solution {
public:
    unordered_map<string, bool> m;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s))
        {
            return m[s];
        }
        
        for(auto w : wordDict)
        {
            if(s.substr(0, w.size()) == w)
            {
                if(s.size() == w.size())
                {
                    return m[s] = true;
                }
                else
                {
                    if(wordBreak(s.substr(w.size()), wordDict))
                    {
                        return m[s] = true;
                    }
                }
            }
        }
        
        return m[s] = false;
    }
};
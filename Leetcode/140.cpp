class Solution {
public:
    unordered_map<string, vector<string>> m;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if(m.count(s))
        {
            return m[s];
        }
        
        vector<string> ret;
        
        for(auto w : wordDict)
        {
            if(s.substr(0, w.size()) == w)
            {
                if(s.size() == w.size())
                {
                    ret.push_back(w);
                }
                else
                {
                    vector<string> r = wordBreak(s.substr(w.size()), wordDict);
            
                    for(string str : r)
                    {
                        ret.push_back(w + " " + str);
                    }
                }
            }
        }
        
        m[s] = ret;
        return m[s];
    }
};
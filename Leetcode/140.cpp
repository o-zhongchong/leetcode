class Solution {
public:
    unordered_map<string, vector<string>> m;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        return dfs(s, wordDict);
    }
    
    vector<string> dfs(string s, vector<string>& wordDict)
    {
        if(m.count(s))
        {
            return m[s];
        }
        
        if(s.empty())
        {
            return {""};
        }
        
        vector<string> ret;
        
        for(auto word : wordDict)
        {
            if(s.substr(0, word.size()) != word)
            {
                continue;
            }
            
            vector<string> r = dfs(s.substr(word.size()), wordDict);
            
            for (string str : r) 
            {
                ret.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        
        return ret;
    }
};
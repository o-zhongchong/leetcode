class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int len1 = words.size();
        
        for(int i=0; i<len1; ++i)
        {
            int len2 = words[i].size();
            
            for(int j=0; j<len2; ++j)
            {
                string t1 = words[i].substr(0, j+1);
                prefix_map[t1].push_back(i);
                
                string t2 = words[i].substr(len2-j-1, j+1);
                suffix_map[t2].push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(!prefix_map.count(prefix) || !suffix_map.count(suffix))
        {
            return -1;
        }
        
        vector<int> pre = prefix_map[prefix];
        vector<int> suf = suffix_map[suffix];
        
        for(int i=pre.size()-1, j=suf.size()-1; i>=0 && j>=0; )  
        {
            if(pre[i] == suf[j])
            {
                return pre[i];
            }
            
            if(pre[i] > suf[j])
            {
                --i;
            }
            
            if(pre[i] < suf[j])
            {
                --j;
            }
        }
        
        return -1;
    }
    
protected:
    unordered_map<string, vector<int>> prefix_map;
    unordered_map<string, vector<int>> suffix_map;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
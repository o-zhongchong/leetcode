class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        vector<int> cnt(26, 0);
        vector<int> visited(26, 0);
        string ret;
        
        for(int i=0; i<len; ++i)
        {
            int c = s[i] - 'a';
            ++cnt[c];
        }
        
        for(int i=0; i<len; ++i)
        {
            int c = s[i] - 'a';
            --cnt[c];
            
            if(visited[c])
            {
                continue;
            }
            
            while(!ret.empty() && s[i] < ret.back() && cnt[ret.back() - 'a'])
            {
                visited[ret.back() - 'a'] = 0;
                ret.pop_back();
            }
            
            ret.push_back(s[i]);
            visited[c] = 1;
        }
        
        return ret;
    }
};
class Solution {
public:
    bool isMatch(const string &s1, const string &s2, 
                 unordered_set<string> &pass, unordered_set<string> &out)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        
        for(int i=0, j=0; i<len1; ++i)
        {
            if(j < len2 && s1[i] == s2[j])
            {
                ++j;
            }
            
            if(j >= len2)
            {
                pass.insert(s2);
                return true;
            }
        }
        
        out.insert(s2);
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        unordered_set<string> pass, out;
        
        for(auto word: words)
        {
            if(!out.count(word) && (pass.count(word) || isMatch(s, word, pass, out)) )
            {
                ++ret;
            }
        }
        
        return ret;
    }
};
class Solution {
public:
    vector<int> helper(string &str)
    {
        vector<int> ret(26, 0);
        
        for(auto &c: str)
        {
            ++ret[c-'a'];
        }
        
        return ret;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int len1 = A.size();
        int len2 = B.size();
        vector<int> char_cnt(26, 0);
        vector<string> ret;
        
        for(int i=0; i<len2; ++i)
        {
            vector<int> t = helper(B[i]);
            
            for(int j=0; j<26; ++j)
            {
                char_cnt[j] = max(char_cnt[j], t[j]);
            }
        }
        
        for(int i=0; i<len1; ++i)
        {
            vector<int> t = helper(A[i]);
            
            bool isUniversal = true;
            
            for(int j=0; j<26; ++j)
            {
                if(t[j] < char_cnt[j])
                {
                    isUniversal = false;
                    break;
                }
            }
            
            if(isUniversal)
            {
                ret.push_back(A[i]);
            }
        }
        
        return ret;
    }
};
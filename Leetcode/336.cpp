class Solution {
public:
    bool isPalindrome(const string &s)
    {
        int left = 0;
        int right = s.size()-1;
        
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        unordered_map<string,int> m;
        vector<vector<int>> ret;
        
        for(int i=0; i<len; ++i)
        {
            m[words[i]] = i;
        }
        
        for(int i=0; i<len; ++i)
        {
            int sz = words[i].size();
            
            for(int j=1; j<=sz; ++j)
            {
                string p1 = words[i].substr(0,j);
                string p2 = words[i].substr(j);
                string r(p2.rbegin(), p2.rend());
                
                if(isPalindrome(p1) && m.count(r))
                {
                    ret.push_back(vector<int>{m[r],i});
                }
            }
            
            for(int j=0; j<=sz; ++j)
            {
                string p1 = words[i].substr(0,j);
                string p2 = words[i].substr(j);
                string r(p1.rbegin(), p1.rend());
                
                if(isPalindrome(p2) && m.count(r) && m[r] != i)
                {
                    ret.push_back(vector<int>{i,m[r]});
                }
            }
        }
        
        return ret;
    }
};
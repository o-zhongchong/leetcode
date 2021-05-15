class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> ret;
        int len = s.size();
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(s[i] == ' ')
            {
                if(i - j > 0)
                {
                    string t = s.substr(j, i-j);
                    ret.push_back(t);
                }
                
                j = i + 1;
            }
            else if(s[i] != ' ' && i == len-1)
            {
                if(len - j > 0)
                {
                    string t = s.substr(j, len-j);
                    ret.push_back(t);
                }
                
                j = i + 1;
            }
        }
        
        return ret;
    }
    
    static bool comp(const string &s1, const string &s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        return s1[len1-1] < s2[len2-1]; 
    }
    
    string sortSentence(string s) {
        vector<string> str_split = split(s);
        sort(str_split.begin(), str_split.end(), comp);
        string ret = "";
        
        for(auto &t : str_split)
        {
            int len = t.size();
            string tmp = t.substr(0, len-1);
            
            if(ret.empty())
            {
                ret += tmp;
            }
            else
            {
                ret += " " + tmp;
            }
        }
        
        return ret;
    }
};
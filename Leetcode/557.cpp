class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        if( s.empty() )
            return string("");
        
        splitStr(s," ",vec);
        for( auto &str: vec)
        {
            rStr(str);
        }
        
        string ret = vec[0];
        for(int i=1;i<vec.size();++i)
            ret += " " + vec[i];
        return ret;
    }
protected:
    int splitStr(string s, string split, vector<string> &vec)
    {
        int start = 0, pos = 0, len = split.size();
        pos = s.find(split,start);
        while( pos != string::npos )
        {
            string substr = s.substr(start,pos-start);
            start = pos + len;
            vec.push_back(substr);
            pos  = s.find(split,start);
        }
        if( start < s.size() )
        {
            string substr = s.substr(start);
            vec.push_back(substr);
        }
        return 0;
    }
    int rStr(string &s)
    {
        int i=0, j = s.size()-1;
        while( i < j )
        {
            swap(s[i],s[j]);
            ++i;
            --j;
        }
        return 0;
    }
};
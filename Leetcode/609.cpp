class Solution {
public:
    vector<string> split(string& s)
    {
        vector<string> ret;
        int len = s.size();
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(s[i] == ' ')
            {
                string t = s.substr(j,i-j);
                ret.push_back(t);
                j = i + 1;
                continue;
            }
            
            if(i == len - 1)
            {
                string t = s.substr(j,len-j);
                ret.push_back(t);
            }
        }
        
        return ret;
    }
    
    string split2(string& s)
    {
        int len = s.size();
        int i = s.find('(');
        string ret = s.substr(0,i);
        s = s.substr(i+1, len-1-(i+1));
        return ret;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> dupfile;
        vector<vector<string>> ret;
        
        for(string s : paths)
        {
            vector<string> files = split(s);
            int len = files.size();
            
            for(int i=1; i<len; ++i)
            {
                string path = files[0] + "/" + split2(files[i]);
                
                if(dupfile.find(files[i]) == dupfile.end())
                {
                    dupfile[files[i]] = vector<string>(1, path);
                }
                else
                {
                    dupfile[files[i]].push_back(path);
                }
            }
        }
        
        for(auto &f : dupfile)
        {
            if(f.second.size() > 1)
            {
                ret.push_back(f.second);
            }
        }
        
        return ret;
    }
};
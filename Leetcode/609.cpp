class Solution {
public:
    vector<string> split(string s, char d)
    {
        vector<string> ret;
        int len = s.size();
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(s[i] == d)
            {
                if(i - j > 0)
                {
                    ret.push_back(s.substr(j, i-j));
                }
                
                j = i + 1;
            }
            else if(s[i] != d && i == len-1)
            {
                if(len - j > 0)
                {
                    ret.push_back(s.substr(j, len-j));
                }
                
                j = i + 1;
            }
        }
        
        return ret;
    }
    
    vector<string> getContent(string file)
    {
        string::size_type pos;
         
        if( (pos = file.find('(')) != string::npos)
        {
            int len = file.size();
            string filename = file.substr(0, pos);
            string content = file.substr(pos+1, len-1);
            return {filename, content};
        }
        
        return {};
    }
    
    void helper(vector<string> &files, unordered_map<string, vector<string>> &dupfiles)
    {
        if(files.empty())
        {
            return;
        }
        
        string dir = files[0];
        int len = files.size();
        
        for(int i=1; i<len; ++i)
        {
            vector<string> file = getContent(files[i]);
            
            if(file.size() == 2)
            {
                dupfiles[file[1]].push_back(dir + "/" + file[0]);
            }
        }
        
        return;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dupfiles;
        vector<vector<string>> ret;
        
        for(auto &path : paths)
        {
            vector<string> files = split(path, ' ');
            helper(files, dupfiles);
        }
        
        for(auto &fs : dupfiles)
        {
            if(fs.second.size() > 1)
            {
                ret.push_back(fs.second);
            }
        }
        
        return ret;
    }
};
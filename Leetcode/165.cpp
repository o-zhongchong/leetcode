class Solution {
public:
    vector<int> get_version(std::string ver)
    {
        vector<int> ret;
        int len = ver.size();
        int start = 0;
        
        for(int i = 0; i < len; ++i)
        {
            if(ver[i] == '.' && i > start)
            {
                string s = ver.substr(start, i - start);
                int v = std::stoi(s);
                ret.push_back(v);
                start = i + 1;
            }
        }
        
        if(start != len)
        {
            string s = ver.substr(start, len - start);
            int v = std::stoi(s);
            ret.push_back(v);
        }
        
        return ret;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = get_version(version1);
        vector<int> ver2 = get_version(version2);
        int len1 = ver1.size();
        int len2 = ver2.size();
        
        for(int i=0, j=0; i<len1 || j<len2; ++i, ++j)
        {
            int v1, v2;
            v1 = v2 = 0;
            
            if(i<len1)
            {
                v1 = ver1[i];    
            }
            
            if(j<len2)
            {
                v2 = ver2[j];
            }
            
            if(v1 > v2)
            {
                return 1;
            }
            else if(v1 < v2)
            {
                return -1;
            }
        }
        
        return 0;
    }
};
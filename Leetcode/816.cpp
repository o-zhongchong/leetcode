class Solution {
public:
    vector<string> split(string x)
    {
        vector<string> ret;
        int len = x.size();
        
        for(int i=0; i<len; ++i)
        {
            string left = x.substr(0, i+1);
            string right = "";
            
            if(i+1 < len)
            {
                right = x.substr(i+1, len-i-1);
            }
            
            if(left.size() > 1 && left[0] == '0')
            {
                continue;
            }
            
            if(!right.empty() && right[right.size() - 1] == '0')
            {
                continue;
            }
            
            if(right.empty())
            {
                ret.push_back(left);
            }
            else
            {
                ret.push_back(left + "." + right);
            }
        }
        
        return ret;
    }
    
    vector<string> helper(string x, string y)
    {
        vector<string> x_split = split(x);
        vector<string> y_split = split(y);
        int len1 = x_split.size();
        int len2 = y_split.size();
        vector<string> ret;
        
        if(len1 == 0 || len2 == 0)
        {
            return ret;
        }
        
        for(int i=0; i<len1; ++i)
        {
            for(int j=0; j<len2; ++j)
            {
                ret.push_back("(" + x_split[i] + ", " + y_split[j] + ")");
            }
        }
        
        return ret;
    }
    
    vector<string> ambiguousCoordinates(string s) {
        if(s.size() < 4)
        {
            return {};
        }
        
        int len = s.size();
        vector<string> ret;
        
        for(int i=2; i<len-1; ++i)
        {
            string x = s.substr(1, i-1);
            string y = s.substr(i, len-1-i);
            cout<<x<<" "<<y<<endl;
            
            vector<string> t = helper(x, y);
            
            for(string &s : t)
            {
                ret.push_back(s);
            }
        }
        
        return ret;
    }
};
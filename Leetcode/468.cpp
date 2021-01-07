class Solution {
public:
    vector<string> split(string &IP, char delimiter)
    {
        vector<string> ret;
        int len = IP.size();
        int pre = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(IP[i] == delimiter)
            {
                string s = IP.substr(pre, i-pre);
                ret.push_back(s);
                pre = i + 1;
            }
        }
        
        string s = IP.substr(pre, len-pre);
        ret.push_back(s);
        
        return ret;
    }
    
    bool validIPv4(string &IP)
    {
        vector<string> nums = split(IP, '.');
        int len = nums.size();
        
        if(len != 4)
        {
            return false;
        }
        
        for(int i=0; i<len; ++i)
        {
            int sz = nums[i].size();
            
            if(sz <= 0 || sz > 3)
            {
                return false;
            }
            
            for(auto c : nums[i])
            {
                if(c >= '0' && c <= '9')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            int n = stoi(nums[i]);
            
            if(n < 0 || n > 255)
            {
                return false;
            }
            
            if(nums[i].size() > 1 && nums[i][0] == '0')
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool validIPv6(string &IP)
    {
        vector<string> IP_split = split(IP, ':');
        int len = IP_split.size();
        
        if(len != 8)
        {
            return false;
        }
        
        for(int i=0; i<len; ++i)
        {
            string s= IP_split[i];
            int sz = s.size();
            
            if(sz <= 0 || sz > 4)
            {
                return false;
            }
            
            for(auto c : s)
            {
                if(c >= '0' && c <= '9')
                {
                    continue;
                }
                else if(c >= 'a' && c <= 'f')
                {
                    continue;
                }
                else if(c >= 'A' && c <= 'F')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    string validIPAddress(string IP) {
        if(validIPv4(IP) )
        {
            return "IPv4";
        }
        
        if(validIPv6(IP))
        {
            return "IPv6";
        }
        
        return "Neither";
    }
};
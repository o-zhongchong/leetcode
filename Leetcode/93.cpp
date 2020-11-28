class Solution {
public:
    bool ip_check(string addr)
    {
        int len = addr.size();
        if(len <=0 || len > 3)
        {
            return false;
        }
        
        if(addr == "0")
        {
            return true;
        }
        
        if(len < 3 && addr[0] != '0')
        {
            return true;
        }
        
        if(len == 3 && addr[0] != '0' && addr <= "255")
        {
            return true;
        }
        
        return false;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int len = s.size();
        
        for(int i=1; i<=3; ++i)
        {
            for(int j=1; j<=3; ++j)
            {
                for(int k=1; k<=3; ++k)
                {
                    if(i < len && i + j < len && i + j + k < len)
                    {
                        string x1 = s.substr(0, i);
                        string x2 = s.substr(i, j);
                        string x3 = s.substr(i+j, k);
                        string x4 = s.substr(i+j+k, len-i-j-k);
                        
                        if(ip_check(x1) && ip_check(x2)
                          && ip_check(x3) && ip_check(x4))
                        {
                            string s = x1 + "." + x2 + "." + x3 + "." + x4;
                            ret.push_back(s);
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};
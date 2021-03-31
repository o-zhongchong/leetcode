class Solution {
public:
    int checkStamp(int index, string &stamp, string &target)
    {
        int m = stamp.size();
        int n = target.size();
        int cnt = 0;
        
        for(int i=0; i<m; ++i)
        {
            if(index + i >= n)
            {
                return false;
            }
            
            if(stamp[i] != target[index + i] && target[index + i] != '?')
            {
                return false;
            }
            
            if(target[index + i] == '?')
            {
                ++cnt;
            }
        }
        
        return cnt < m;
    }
    
    int change(int index, string &stamp, string &target)
    {
        int m = stamp.size();
        int n = target.size();
        int cnt = 0;
        
        for(int i=0; i<m; ++i)
        {
            if(index + i < n && target[index + i] != '?')
            {
                target[index + i] = '?';
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ret;
        int m = stamp.size();
        int n = target.size();
        int index = target.find(stamp);
        int cnt = n;
        
        if(index == string::npos)
        {
            return vector<int>{};
        }
        else
        {
            ret.push_back(index);
            cnt -= m;
            
            for(int i=0; i<m; ++i)
            {
                target[index+i] = '?';
            }
        }
        
        while(cnt > 0)
        {
            bool checkOK = false;
            
            for(int i = 0; i <= n - m; ++i)
            {
                if(checkStamp(i, stamp, target))
                {
                    checkOK = true;
                    ret.push_back(i);
                    cnt -= change(i, stamp, target);
                    break;
                }
            }
            
            if(!checkOK)
            {
                break;
            }
        }
        
        reverse(ret.begin(), ret.end());
        return cnt > 0 ? vector<int>{} : ret;
    }
};
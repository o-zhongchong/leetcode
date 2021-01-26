class Solution {
public:
    bool isLike(string& time1, string& time2)
    {
        int len1 = time1.size();
        int len2 = time2.size();
        
        if(len1 != len2)
        {
            return false;
        }
        
        for(int i=0; i<len1; ++i)
        {
            if(time2[i] != '?' && time1[i] != time2[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> split(string& time)
    {
        int len = time.size();
        vector<string> ret;
        
        for(int i=0, j=0; i<len; ++i)
        {
            if(time[i] == ':')
            {
                ret.push_back(time.substr(j, i-j));
                j = i+1;
            }
            else if(time[i] != ':' && i == len-1)
            {
                ret.push_back(time.substr(j, len-j));
            }
        }
        
        return ret;
    }
    
    string maximumTime(string time) {
        int hour, minute;
        vector<string> times = split(time);
        string ret;
        
        for(hour = 23; hour >= 0; --hour)
        {
            string hour_s = to_string(hour);
            
            if(hour_s.size() == 1)
            {
                hour_s.insert(0, "0");
            }
            
            if(isLike(hour_s, times[0]))
            {
                ret += hour_s + ":";
                break;
            }
        }
        
        for(minute = 59; minute >= 0; --minute)
        {
            string minute_s = to_string(minute);
            
            if(minute_s.size() == 1)
            {
                minute_s.insert(0, "0");
            }
            
            if(isLike(minute_s, times[1]))
            {
                ret += minute_s;
                break;
            }
        }
        
        return ret;
    }
};
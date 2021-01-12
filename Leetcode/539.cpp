class Solution {
public:
    vector<string> split(string& s, char c)
    {
        vector<string> ret;
        int len = s.size(), pre = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(s[i] == c)
            {
                ret.push_back(s.substr(pre, i-pre));
                pre = i+1;
            }
        }
        
        if(pre < len)
        {
            ret.push_back(s.substr(pre, len-pre));
        }
        
        return ret;
    }
    
    int toMin(string& t)
    {
        int hour, min;
        vector<string> time = split(t, ':');
        hour = stoi(time[0]);
        min = stoi(time[1]);
        return hour * 60 + min;
    }
        
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timePoints2;
        int len = timePoints.size();
        int ret = 1440;
        
        for(int i=0; i<len; ++i)
        {
            int min = toMin(timePoints[i]);
            timePoints2.push_back(min);
        }
        
        sort(timePoints2.begin(), timePoints2.end());
        int diff = abs(timePoints2[len-1] - timePoints2[0]);
        ret = min(1440 - diff, diff);
        
        for(int i=1; i<len; ++i)
        {
            diff = abs(timePoints2[i] - timePoints2[i-1]);
            diff = min(1440 - diff, diff);
            ret = min(ret, diff);
        }
        
        return ret;
    }
};
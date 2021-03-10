class Solution {
public:
    int getBeauty(vector<int> &freq)
    {
        if(freq.empty())
        {
            return 0;
        }
        
        int min_freq = -1;
        int max_freq = -1;
        
        for(auto &f : freq)
        {
            if(f > 0)
            {
                max_freq == -1 ? max_freq = f : max_freq = max(max_freq, f);
                min_freq == -1 ? min_freq = f : min_freq = min(min_freq, f);
            }
        }
        
        return max_freq - min_freq;
    }
    
    int beautySum(string s) {
        int ret = 0;
        int len = s.size();
        
        for(int i=3; i<=len; ++i)
        {
            vector<int> freq(26, 0);
            
            for(int j=0; j<i; ++j)
            {
                ++freq[s[j] - 'a'];
            }
            
            ret += getBeauty(freq);
            
            for(int j=1; j<=len-i; ++j)
            {
                ++freq[s[j+i-1] - 'a'];
                --freq[s[j-1] - 'a'];
                ret += getBeauty(freq);
            }
        }
        
        return ret;
    }
};
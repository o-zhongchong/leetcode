class Solution {
public:
    string getStr(int x, int y)
    {
        string r = "";
        r += to_string(x);
        r += "->";
        r += to_string(y);
        return r;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }
        
        int len = nums.size();
        int start = 0;
        vector<string> ret;
        
        for(int i=1; i<len; ++i)
        {
            if(nums[i] != nums[i-1] + 1)
            {
                if(i-1 == start)
                {
                    string s = to_string(nums[start]);
                    ret.push_back(s);
                }
                else
                {
                    string s = getStr(nums[start], nums[i-1]);
                    ret.push_back(s);
                }
                
                start = i;
            }
        }
        
        if(start == len - 1)
        {
            string s = to_string(nums[start]);
            ret.push_back(s);
        }
        else
        {
            string s = getStr(nums[start], nums[len-1]);
            ret.push_back(s);
        }
        
        return ret;
    }
};
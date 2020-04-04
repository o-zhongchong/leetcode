class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        if( len<=0 )
            return "";
        
        string ret;
        vector<string> str;
        
        for(int i=0; i<len; ++i)
            str.push_back(to_string(nums[i]));
        
        sort(str.begin(), str.end(), Solution::comp);

        for(int i=0; i<len; ++i)
            ret = ret + str[i];
        
        while('0' == ret[0] && ret.size()>1 )
        {
            ret.erase(ret.begin());
        }
        
        return ret;
    }
    
    static bool comp(string a, string b)
    {
        string ab=a+b;
        string ba=b+a;
        
        if(ab > ba)
            return true;
        
        return false;
    }
};
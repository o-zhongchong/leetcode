class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())
        {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = {{},{nums[0]}};
        int last = 1;
        int len = nums.size();
        
        for(int i=1; i<len; ++i)
        {
            int newLen = ret.size();
            int j = 0;
            
            if(nums[i] == nums[i-1])
            {
                j = last;
            }
            
            last = newLen;
            
            for(; j < newLen; ++j)
            {
                vector<int> c = ret[j];
                c.push_back(nums[i]);
                ret.push_back(c);
            }
        }
        
        return ret;
    }
};
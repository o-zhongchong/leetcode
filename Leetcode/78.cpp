class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        
        for(int i = 0; i < pow(2, len); ++i)
        {
            int m = i;
            int j = 0;
            vector<int> subset;
            
            while(m)
            {
                if(m & 1)
                {
                    subset.push_back(nums[j]);
                }
                
                m = m >> 1;
                ++j;
            }
            
            ret.push_back(subset);
        }
        
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        for(int i=0; i<numRows; ++i)
        {
            if(i == 0)
            {
                ret.push_back({1});
                continue;
            }
            
            int len = ret[i-1].size();
            vector<int> nums(1,1);
            
            for(int j=1; j<len; ++j)
            {
                nums.push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            
            nums.push_back(1);
            ret.push_back(nums);
        }
        
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < 1)
        {
            return {};
        }
        
        vector<vector<int>> ret;
        
        for(int i=1; i<=numRows; ++i)
        {
            vector<int> row(1,1);
            
            for(int j=1; j<i; ++j)
            {
                if(j < i-1)
                {
                    row.push_back(ret[i-2][j-1] + ret[i-2][j]);
                }
                else
                {
                    row.push_back(1);
                }
            }
            
            ret.push_back(row);
        }
        
        return ret;
    }
};
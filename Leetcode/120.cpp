class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len1 = triangle.size();
        int ret = triangle[0][0];
        
        for(int i=1; i<len1; ++i)
        {
            int len2 = triangle[i].size();
            int min_path = INT_MAX;
            
            for(int j=0; j<len2; ++j)
            {
                if(j == 0)
                {
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j == len2-1)
                {
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else
                {
                    triangle[i][j] = min(triangle[i][j] + triangle[i-1][j], 
                                         triangle[i][j] + triangle[i-1][j-1]);
                }
                
                min_path = min(min_path, triangle[i][j]);
            }
            
            ret = min_path;
        }
        
        return ret;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        if(m == 0)
        {
            return 0;
        }
        
        int min_cost = 0;
        int n = triangle[0].size();
        
        for(int i=0; i<n; ++i)
        {
            if(i == 0 || triangle[0][i] < min_cost)
            {
                min_cost = triangle[0][i];
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            int n1 = triangle[i-1].size();
            int n2 = triangle[i].size();
            
            for(int j=0; j<n2; ++j)
            {
                int x1,x2;
                x1 = x2 = INT_MAX;
                
                if(j-1 >= 0 && j-1 < n1)
                {
                    x1 = triangle[i][j] + triangle[i-1][j-1];
                }
                
                if(j >=0 && j < n1)
                {
                    x2 = triangle[i][j] + triangle[i-1][j];
                }
                
                if(x1 < x2)
                {
                    triangle[i][j] = x1;
                }
                else
                {
                    triangle[i][j] = x2;
                }
                
                if(j == 0 || triangle[i][j] < min_cost)
                {
                    min_cost = triangle[i][j];
                }
            }
        }
        
        return min_cost;
    }
};
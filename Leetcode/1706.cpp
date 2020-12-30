class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return {};
        }
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ret(n, -1);
        
        for(int i=0; i<n; ++i)
        {
            int j = 0, k = i;
            
            while(j < m)
            {
                if(grid[j][k] == 1 && k + 1 < n && grid[j][k+1] == 1)
                {
                    ++k;
                }
                else if(grid[j][k] == -1 && k - 1 >= 0 && grid[j][k-1] == -1)
                {
                    --k;
                }
                else
                {
                    break;
                }
                
                ++j;
            }
            
            if(j == m)
            {
                ret[i] = k;
            }
        }
        
        return ret;
    }
};
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();
        unordered_map<int, int> cnt;
        
        for(int i=0; i<m; ++i)
        {
            int n = wall[i].size();
            
            for(int j=1; j<n; ++j)
            {
                wall[i][j] += wall[i][j-1];
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            int n = wall[i].size();
            
            for(int j=0; j<n; ++j)
            {
                ++cnt[wall[i][j]];
            }
        }
        
        int n = wall[0].size();
        cnt[wall[0][n-1]] = 0;
        int line = wall[0][n-1];
        
        for(auto i: cnt)
        {
            if(i.second > cnt[line])
            {
                line = i.first;
            }
        }
        
        return m - cnt[line];
    }
};
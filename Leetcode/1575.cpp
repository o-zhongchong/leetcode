class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        
        return moveToCity(locations, start, finish, fuel, dp);
    }
    
    int moveToCity(vector<int>& locations, int start, int finish, 
                   int fuel, vector<vector<int>>& dp)
    {
        if(fuel < 0)
        {
            return 0;
        }
        
        const int n = locations.size();
        int ans = (start == finish) ? 1 : 0;
        
        if(dp[start][fuel] != -1)
        {
            return dp[start][fuel];
        }

        for(int i = 0; i < n; ++i)
        {
            int cost = abs(locations[start] - locations[i]);
            
            if(i != start)
            {
                ans = (ans + moveToCity(locations, i, finish, fuel-cost, dp))
                    % 1000000007;
            }
        }
        
        dp[start][fuel] = ans;
        
        return ans;
    }
};
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int n = locations.size();
        int** dp = new int*[n];
        
        for(int i=0; i<n; ++i)
        {
            dp[i] = new int[fuel+1];
        }
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<fuel+1; ++j)
            {
                dp[i][j] = -1;
            }
        }
        
        return dfs(locations, start, finish, fuel, dp);
    }
    
    int dfs(vector<int>& locations, int curCity, int finishCity, 
                   int fuel, int** dp)
    {
        if(fuel < 0)
        {
            return 0;
        }
        
        const int n = locations.size();
        int ans = (curCity == finishCity) ? 1 : 0;
        
        if(dp[curCity][fuel] != -1)
        {
            return dp[curCity][fuel];
        }

        for(int i = 0; i < n; ++i)
        {
            int cost = abs(locations[curCity] - locations[i]);
            
            if(i != curCity)
            {
                ans = (ans + dfs(locations, i, finishCity, fuel-cost, dp))
                    % 1000000007;
            }
        }
        
        dp[curCity][fuel] = ans;
        
        return ans;
    }
};
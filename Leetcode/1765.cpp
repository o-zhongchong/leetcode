class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        if(isWater.empty() || isWater[0].empty())
        {
            return {};
        }
        
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue<pair<int, int>> task;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(isWater[i][j])
                {
                    isWater[i][j] = 0;
                    visit[i][j] = 1;
                    task.push(make_pair(i,j));
                }
            }
        }
        
        while(!task.empty())
        {
            pair<int,int> cell = task.front();
            int h = isWater[cell.first][cell.second];
            int step[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            task.pop();
            
            for(int k = 0; k < 4; ++k)
            {
                int p = cell.first + step[k][0];
                int q = cell.second + step[k][1];
                
                if(p >= 0 && p < m && q >= 0 && q < n)
                {
                    if(visit[p][q] == 0)
                    {
                        visit[p][q] = 1;
                        isWater[p][q] = h + 1;
                        task.push(make_pair(p,q));
                    }
                }
            }
        }
        
        return isWater;
    }
};
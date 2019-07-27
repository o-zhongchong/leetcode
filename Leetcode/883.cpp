class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        unsigned int ret = 0;
        vector<int> front, side;

        for (unsigned int i = 0; i < grid.size(); ++i)
        {
            for (unsigned int j = 0; j < grid.size(); ++j)
            {
                if (i < side.size())
                {
                    if (grid[i][j] > side[i])
                        side[i] = grid[i][j];
                }
                else
                    side.push_back(grid[i][j]);

                if (j < front.size())
                {
                    if (grid[i][j] > front[j])
                        front[j] = grid[i][j];
                }
                else
                    front.push_back(grid[i][j]);
                
                if(grid[i][j])
                    ++ret;
            }
        }

        for (auto &i : side)
            ret += i;

        for (auto &i : front)
            ret += i;

        return ret;
    }
};
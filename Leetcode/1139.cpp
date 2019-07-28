class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ret = 0, max_scale;

        for (int scale = 1; scale <= grid.size() && scale <= grid[0].size(); ++scale)
        {
            for (int i = 0; i < grid.size() - scale + 1; ++i)
                for (int j = 0; j < grid[0].size() - scale + 1; ++j)
                {
                    if ( check_square(grid, i, j, scale) )
                    {
                        int square = pow(scale, 2);
                        if (square > ret)
                            ret = square;
                    }
                }
            }
        return ret;
    }
private:
    bool check_square(vector<vector<int>>& grid, int x, int y, int scale)
    {
        int edge_x, edge_y;
        if (scale > 1)
        {
            edge_x = x + scale - 1;
            edge_y = y + scale - 1;
        }

        for (int i = 0; i < scale; ++i)
            for (int j = 0; j < scale; ++j)
            {
                int target_x = x + i;
                int target_y = y +j;

                if (target_x >= 0 && target_x < grid.size() && target_y >= 0 && target_y < grid[0].size())
                {
                    if (scale > 1 && target_x > x && target_x < edge_x && target_y>y && target_y < edge_y)
                        continue;

                    if (grid[target_x][target_y] == 0)
                        return false;
                }
                else
                    return false;
            }
        return true;
    }
};
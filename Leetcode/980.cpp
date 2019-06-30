class Solution {
public:
    int isWorkOver(vector<vector<int>>& grid)
    {
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j)
                if(grid[i][j] == 0)
                    return 0;
        return 1;
    }

    void dfs(stack<pair<int,int>>& work_stack, vector<vector<int>>& grid, int& nums)
    {
        pair<int,int> cur_pos = work_stack.top();
        int x = cur_pos.first;
        int y = cur_pos.second;
        if( grid[x][y] == 2  )
        {
            if( isWorkOver(grid) )
                ++nums;
            return;
        }

        int step[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        for(int i=0; i<4; ++i)
        {
            x = cur_pos.first + step[i][0];
            y = cur_pos.second + step[i][1];
            if(x >=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y] != -1
               && grid[x][y] != 1)
            {
                int tmp = grid[x][y];
                if( grid[x][y] == 0 )
                    grid[x][y] = -1;
                work_stack.push(make_pair(x,y));
                dfs(work_stack, grid, nums);
                work_stack.pop();
                grid[x][y] = tmp;
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        startX = startY = 0;

        for(int x=0; x<grid.size(); ++x)
            for(int y=0; y<grid[x].size(); ++y)
            {
                if(grid[x][y] == 1)
                {
                    startX = x;
                    startY = y;
                }
            }

        stack<pair<int,int>> work_stack;
        int nums=0;
        work_stack.push(make_pair(startX, startY));
        dfs(work_stack, grid, nums);
        return nums;
    }
};

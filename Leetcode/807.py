class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        left_view=[]
        top_view=[]
        res=0
        
        for i,val in enumerate(grid):
            maxN=grid[i][0]
            for j,val in enumerate(grid[i]):
                if grid[i][j] > maxN:
                    maxN = grid[i][j]
            left_view.append(maxN)
        
        for j,val in enumerate(grid[0]):
            maxN=grid[0][j]
            for i,val in enumerate(grid):
                if grid[i][j] > maxN:
                    maxN = grid[i][j]
            top_view.append(maxN)

        for i,val in enumerate(grid):
            for j,val in enumerate(grid[i]):
                res += min(left_view[i], top_view[j]) - grid[i][j]
        return res

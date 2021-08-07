class Solution {
public:
    void helper(vector<vector<int>> &grid, unordered_map<int,int> &island) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> visitQ;
        int step[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        int islandId = -1;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]==1) {
                    grid[i][j] = islandId;
                    visitQ.push(pair<int,int>(i,j));
                    int area = 0;
                    while(!visitQ.empty()) {
                        auto node = visitQ.front();
                        visitQ.pop();
                        ++area;
                        for(int k=0; k<4; ++k) {
                            int p = node.first + step[k][0];
                            int q = node.second + step[k][1];
                            if(p >= 0 && p < m && q >= 0 && q < n 
                               && grid[p][q]==1) {
                                grid[p][q] = islandId;
                                visitQ.push(pair<int,int>(p,q));
                            }
                        }
                    }
                    island[islandId] = area;
                    --islandId;
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int,int> island;
        helper(grid,island);
        int step[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        int ret = 0;
        for(auto i : island) {
            ret = max(ret, i.second);
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 0) {
                    set<int> islandId;
                    int area = 1;
                    for(int k=0; k<4; ++k) {
                        int p = i + step[k][0];
                        int q = j + step[k][1];
                        if(p >= 0 && p < m && q >= 0 && q < n) {
                            islandId.insert(grid[p][q]);
                        }
                    }
                    for(auto id : islandId) {
                        area += island[id];
                    }
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }
};
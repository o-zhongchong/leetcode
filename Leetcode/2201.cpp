class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n, -1));
        int num = artifacts.size();
        unordered_map<int,int> cnt;
        for(int i=0; i<num; ++i) {
            cnt[i] = (artifacts[i][2]-artifacts[i][0]+1)*(artifacts[i][3]-artifacts[i][1]+1);
            for(int j=artifacts[i][0]; j<=artifacts[i][2]; ++j) {
                for(int k=artifacts[i][1]; k<=artifacts[i][3]; ++k) {
                    grid[j][k] = i;
                }
            }
        }
        num = dig.size();
        int ans = 0;
        for(int i=0; i<num; ++i) {
            int j = grid[dig[i][0]][dig[i][1]];
            if(j != -1) {
                grid[dig[i][0]][dig[i][1]] = -1;
                if(--cnt[j] == 0) ++ans;
            }
        }
        return ans;
    }
};
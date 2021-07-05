class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.empty() || mat[0].empty()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> ret(r, vector<int>(c,0));
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int pos = i*n+j;
                ret[pos/c][pos%c] = mat[i][j];
            }
        }
        
        return ret;
    }
};
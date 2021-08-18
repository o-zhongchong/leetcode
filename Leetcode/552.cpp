class Solution {
public:
    typedef vector<vector<long long>> matrix;
    static const long long M = 1e9 + 7;
public:
    matrix multiply(const matrix &m1, const matrix &m2) {
        int m = m1.size();
        int n = m1[0].size();
        int p = m2.size();
        int q = m2[0].size();
        matrix ret(m, vector<long long>(q,0));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<q; ++j) {
                for(int k=0; k<n; ++k) {
                    ret[i][j] += m1[i][k] * m2[k][j];
                    ret[i][j] %= M;
                }
            }
        }
        return ret;
    }
    matrix power(matrix &mat, int N) {
        int n = mat.size();
        matrix ret(n, vector<long long>(n, 0));
        for(int i=0; i<n; ++i) {
            ret[i][i] = 1;
        }
        while(N) {
            if(N & 1) ret = multiply(ret,mat);
            mat = multiply(mat,mat);
            N >>= 1;
        }
        return ret;
    }
    int checkRecord(int n) {
        matrix mat = {
            {1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        };
        matrix dp0 = {
            {1}, {1}, {0}, {1}, {0}, {0}
        };
        matrix dpN = {
            {0}, {0}, {0}, {0}, {0}, {0}
        };
        long long ret = 0;
        mat = power(mat, n-1);
        dpN = multiply(mat, dp0);
        for(int i=0; i<6; ++i) ret += dpN[i][0];
        return static_cast<int>(ret%M);
    }
};
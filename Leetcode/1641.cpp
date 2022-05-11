typedef vector<vector<int>> matrix;

matrix operator*(const matrix& m1, const matrix& m2) {
    int m = m1.size();
    int n = m1[0].size();
    int p = m2.size();
    int q = m2[0].size();
    if(n != p) return {};
    matrix ans(m, vector<int>(q, 0));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<q; ++j) {
            for (int k=0; k<n; ++k) {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return ans;
}

matrix power(const matrix& m1, int n) {
    int N = m1.size();
    matrix ans(N, vector<int>(N, 0));
    matrix w = m1;
    for (int i=0; i<N; ++i) ans[i][i] = 1;
    while (n) {
        if (n & 1) {
            ans = ans * w;
        }
        w = w * w;
        n >>= 1;
    }
    return ans;
}

class Solution {
public:
    int countVowelStrings(int n) {
        const matrix M = {
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 1, 0, 0},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1}
        };
        const matrix mat1 = {
            {1},{1},{1},{1},{1}
        };
        matrix mat2 = power(M, n-1) * mat1;
        int ans = 0;
        for (int i=0; i<5; ++i) {
            ans += mat2[i][0];
        }
        return ans;
    }
};

typedef vector<vector<int64_t>> Mat;

Mat operator*(const Mat& m1, const Mat& m2) {
    int m = m1.size();
    int n = m1[0].size();
    int p = m2.size();
    int q = m2[0].size();
    const int64_t mod = 1e9 + 7;
    if(n != p) return {};
    Mat m3(m, vector<int64_t>(q,0));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<q; ++j) {
            for(int k=0; k<n; ++k) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            m3[i][j] %= mod;
        }
    }
    return m3;
}

Mat quickPow(Mat mat, int n) {
    int len = mat.size();
    Mat ans(len, vector<int64_t>(len, 0));
    for(int i=0; i<len; ++i) {
        ans[i][i] = 1;
    }
    while(n) {
        if(n & 1) ans = ans * mat;
        mat = mat * mat;
        n >>= 1;
    }
    return ans;
}

class Solution {
public:
    int numTilings(int n) {
        Mat base = {{5}, {2}, {1}};
        if(n <= 3) return base[3-n][0];
        Mat a = {
            {2,0,1},
            {1,0,0},
            {0,1,0},
        };
        Mat ans = quickPow(a, n-3) * base;
        return ans[0][0];
    }
};

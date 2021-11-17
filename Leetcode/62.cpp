class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(m+n-2, min(m-1,n-1));
    }
private:
    int helper(int64_t m, int64_t n) {
        int64_t ret = 1;
        for(int64_t i=0; i<n; ++i) {
            ret = ret * (m-i) / (i+1); 
        }
        return (int)ret;
    }
};
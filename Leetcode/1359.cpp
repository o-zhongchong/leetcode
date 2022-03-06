class Solution {
public:
    int countOrders(int n) {
        const int M = 1e9 + 7;
        long long ans = 1;
        for(int i=2; i<=n; ++i) {
            ans = (i*(2*i-1)*ans) % M;
        }
        return ans;
    }
};
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int64_t lcm = a * b / gcd(a, b);
        int64_t left = 1, right = 1e14;
        const int64_t mod = 1e9 + 7;
        while(left < right) {
            int64_t mid = left + (right - left) / 2;
            if(mid/a + mid/b - mid/lcm < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left % mod;
    }
private:
    int gcd(int a, int b) {
        if(a < b) swap(a, b);
        return b == 0 ? a : gcd(b, a%b);
    }
};
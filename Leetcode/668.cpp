class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i=1; i<=m; ++i) {
                cnt += mid > i * n ? n : mid / i; 
            }
            if(cnt < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};
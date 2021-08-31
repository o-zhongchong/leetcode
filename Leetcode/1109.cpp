class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n, 0);
        for(auto &booking : bookings) {
            ret[booking[0] - 1] += booking[2];
            if(booking[1]+1 <= n) {
                ret[booking[1]] -= booking[2];
            }
        }
        for(int i=1; i<n; ++i) {
            ret[i] += ret[i-1];
        }
        return ret;
    }
};
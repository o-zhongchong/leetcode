class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        double trip = 0.0;
        for(auto t : time) trip += 1.0 / t;
        long long left = totalTrips / trip;
        long long right = (long long)time.back() * (long long)totalTrips;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            long long trip = 0;
            for(auto t : time) {
                trip += mid / t;
            }
            if(trip >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
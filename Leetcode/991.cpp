class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue) {
            target = target & 1 ? target + 1 : target / 2;
            ++ans;
        }
        return ans + startValue - target;
    }
};
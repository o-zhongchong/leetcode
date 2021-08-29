class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size();
        int ret = 0;
        for(int i=0; i<len; ++i) {
            int leftOdd = (i + 1) / 2;
            int leftEven = i / 2 + 1;
            int rightOdd = (len - i) / 2;
            int rightEven = (len - 1 - i) / 2 + 1;
            ret += arr[i] * (leftOdd*rightOdd + leftEven*rightEven);
        }
        return ret;
    }
};
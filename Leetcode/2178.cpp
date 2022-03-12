class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};
        vector<long long> ans;
        long long num = 2;
        while(finalSum > 0) {
            if(finalSum >= num) {
                ans.push_back(num);
                finalSum -= num;
                num += 2;
            } else {
                finalSum += ans.back();
                ans.pop_back();
            }
        }
        return ans;
    }
};
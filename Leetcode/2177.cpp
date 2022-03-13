class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num % 3 == 0)
            ans = {num/3-1, num/3, num/3+1};
        return ans;
    }
};
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int r = 0, sum = 0;
        for(auto n : nums) {
            sum += n;
            r = min(r, sum);
        }
        return 1-r > 0 ? 1-r : 1; 
    }
};
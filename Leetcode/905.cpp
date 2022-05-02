class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums) {
            if(!(n & 1)) ans.push_back(n);
        }
        for(auto n : nums) {
            if(n & 1) ans.push_back(n);
        }
        return ans;
    }
};
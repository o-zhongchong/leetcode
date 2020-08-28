class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        
        for (int n : nums) {
            if(cnt == 0)
            {
                ret = n;
                ++cnt;
                continue;
            }
            
            n == ret ? ++cnt : --cnt;
        }
        
        return ret;
    }
};
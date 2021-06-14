class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0;
        int mx = 0;
        
        for(int i=0, j=0; j<len-1 && i<len; ++i)
        {
            mx = max(mx, i + nums[i]);
            
            if(i == j)
            {
                ++cnt;
                j = mx;
            }
        }
        
        return cnt;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int cnt, pre, cur;
        cnt = pre = cur = 0;
        
        for(int i=0; i<len-1; ++i)
        {
            cur = max(cur, i + nums[i]);
            
            if(i == pre)
            {
                ++cnt;
                pre = cur;
                
                if(cur >= len - 1)
                {
                    break;
                }
            }
        }
        
        return cnt;
    }
};
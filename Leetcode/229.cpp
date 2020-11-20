class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int x, y, cnt1, cnt2;
        x = y = cnt1 = cnt2 = 0;
        vector<int> ret;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] == x)
            {
                ++cnt1;
            }
            else if(nums[i] == y)
            {
                ++cnt2;
            }
            else if(cnt1 == 0)
            {
                x = nums[i];
                ++cnt1;
            }
            else if(cnt2 == 0)
            {
                y = nums[i];
                ++cnt2;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        
        cnt1 = cnt2 = 0;
        
        for(int i=0; i<len; ++i)
        {
            if(nums[i] == x)
            {
                ++cnt1;
            }
            else if(nums[i] == y)
            {
                ++cnt2;
            }
        }
        
        if(cnt1 > len / 3)
        {
            ret.push_back(x);
        }
        
        if(cnt2 > len / 3)
        {
            ret.push_back(y);
        }
        
        return ret;
    }
};
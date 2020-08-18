class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        
        int len = nums.size();
        int m = len - 1;
        int n = (len + 1)/2 - 1;
        
        for(int i = 0; i < len && m < len && n < len; ++i)
        {
            if(i & 1)
            {
                nums[i] = tmp[m--];
            }
            else
            {
                nums[i] = tmp[n--];
            }
        }
        
        return;
    }
};
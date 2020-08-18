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
            nums[i] = i & 1 ? tmp[m--] : tmp[n--];
        }
        
        return;
    }
};
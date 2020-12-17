class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        dfs(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
    
    void dfs(vector<int>& nums, int k, set<vector<int>>& res)
    {
        int len = nums.size();
        
        if(k >= len)
        {
            res.insert(nums);
            return;
        }
        
        for(int i=k; i<len; ++i)
        {
            swap(nums[k], nums[i]);
            dfs(nums, k+1, res);
            swap(nums[k], nums[i]);
        }
        
        return;
    }
};
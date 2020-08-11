class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        int sum = 0;
        
        dfs(candidates, 0, sum, target, cur, ret);
        return ret;
    }
    
    int dfs(vector<int>& candidates, int start, int sum, int target,
                 vector<int> cur, vector<vector<int>>& ret)
    {
        int len = candidates.size();
        if(start >= len)
            return -1;
        
        int c = 0;
        dfs(candidates, start + 1, sum, target, cur, ret);
        
        while(candidates[start] + sum < target)
        {
            ++c;
            cur.push_back(candidates[start]);
            sum = sum + candidates[start];
            dfs(candidates, start + 1, sum, target, cur, ret); 
        }
        
        if(candidates[start] + sum == target)
        {
            ++c;
            cur.push_back(candidates[start]);
            sum = sum + candidates[start];
            ret.push_back(cur);
            
            while(c--)
            {
                cur.pop_back();
                sum = sum - candidates[start];
            }
        }
        
        return 0;
    }
};
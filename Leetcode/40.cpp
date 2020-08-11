class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        set<vector<int>> s;
        vector<int> cur;
        int sum = 0;
        
        dfs(candidates, 0, sum, target, cur, s);
        
        for(auto v: s)
        {
            ret.push_back(v);
        }

        return ret;
    }
    
    int dfs(vector<int>& candidates, int start, int sum, int target,
                 vector<int> cur, set<vector<int>>& s)
    {
        int len = candidates.size();
        if(start >= len)
            return -1;
        
        dfs(candidates, start + 1, sum, target, cur, s);
        
        if(candidates[start] + sum < target)
        {
            cur.push_back(candidates[start]);
            sum = sum + candidates[start];
            dfs(candidates, start + 1, sum, target, cur, s);
            cur.pop_back();
            sum = sum - candidates[start];
        }
        else if(candidates[start] + sum == target)
        {
            cur.push_back(candidates[start]);
            vector<int> t = cur;
            sort(t.begin(), t.end());
            
            if(s.find(t) == s.end())
            {
                s.insert(t);
            }
            
            cur.pop_back();
        }
        
        return 0;
    }
};
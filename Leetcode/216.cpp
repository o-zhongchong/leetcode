class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(k, n, tmp, res);
        return res;
    }
    
    void dfs(int k, int n, vector<int>& t, vector<vector<int>>& res)
    {
        if(k == 0 && n == 0)
        {
            res.push_back(t);
        }
        else if(k == 0 && n != 0)
        {
            return;
        }
        
        int start = 1;
        
        if(!t.empty())
        {
            start = t.back() + 1;
        }
        
        for(int i=start; i<=9; ++i)
        {
            if(n >= i)
            {
                t.push_back(i);
                dfs(k-1, n-i, t, res);
                t.pop_back();
            }
        }
        
        return;
    }
};
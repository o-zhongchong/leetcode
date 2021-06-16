class Solution {
public:
    int dfs(int left, int right, string s, vector<string> &ret)
    {
        if(left > right)
        {
            return 0;
        }
        
        if(left == 0 && right == 0)
        {
            ret.push_back(s);
        }
        
        if(left > 0)
        {
            dfs(left-1, right, s+'(', ret);
        }
        
        if(right > 0)
        {
            dfs(left, right-1, s+')', ret);
        }
        
        return 0;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs(n, n, "", ret);
        return ret;
    }
};
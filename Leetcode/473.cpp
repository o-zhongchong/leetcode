class Solution {
public:
    static bool cmp(const int &a, const int &b)
    {
        return a > b;
    }
    
    int dfs(vector<int> &matchsticks, int idx, vector<int> &edges, bool &ret)
    {
        int len = matchsticks.size();
        
        if(idx >= len)
        {
            ret = true;
            return 0;
        }
        
        for(int i=0; i<4; ++i)
        {
            if(!ret && edges[i] >= matchsticks[idx])
            {
                edges[i] -= matchsticks[idx];
                dfs(matchsticks, idx+1, edges, ret);
                edges[i] += matchsticks[idx];
            }
        }
        
        return 0;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int len = matchsticks.size();
        int sum = 0;
        
        for(int i=0; i<len; ++i)
        {
            sum += matchsticks[i];
        }
        
        if(sum % 4 != 0)
        {
            return false;
        }
        
        sort(matchsticks.begin(), matchsticks.end(), cmp);
        vector<int> edges(4, sum/4);
        bool ret = false;
        dfs(matchsticks, 0, edges, ret);
        return ret;
    }
};
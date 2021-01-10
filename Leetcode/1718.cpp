class Solution {
public:
    void dfs(int x, vector<int> &nums, vector<int> &visit, vector<int> &ret)
    {
        if(ret[0] != 0)
        {
            return;
        }
        
        int len = nums.size();
        int n = visit.size();
        
        if(x >= len)
        {
            ret = nums;
            return;
        }
        
        if(nums[x] != 0)
        {
            dfs(x+1, nums, visit, ret);
            return;
        }
        
        for(int i=n; ret[0] == 0 && i>0; --i)
        {
            if(visit[i-1] == 0)
            {
                if(i == 1)
                {
                    //cout<<x<<" "<<i<<endl;
                    nums[x] = i;
                    visit[i-1] = 1;
                    dfs(x+1, nums, visit, ret);
                    nums[x] = 0;
                    visit[i-1] = 0;
                }
                
                if(i != 1 && x+i < len && nums[x+i] == 0)
                {
                    nums[x] = i;
                    nums[x+i] = i;
                    visit[i-1] = 1;
                    dfs(x+1, nums, visit, ret);
                    nums[x] = 0;
                    nums[x+i] = 0;
                    visit[i-1] = 0;
                }
            }
        }
        
        return;
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<int> ret(2*n-1, 0), tmp(2*n-1, 0);
        vector<int> visit(n, 0);
        dfs(0, tmp, visit, ret);
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visited(n, false);
        vector<vector<int>> ret;
        vector<int> temp;
        helper(0, k, visited, temp, ret);
        return ret;
    }
private:
    void helper(int n, int k, vector<bool> &visited, 
        vector<int> &t, vector<vector<int>> &ret)
    {
        if(k <= 0) {
            ret.push_back(t);
            return;
        }
        int len = visited.size();
        for(int i=n; i<len; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                t.push_back(i + 1);
                helper(i+1, k-1, visited, t, ret);
                t.pop_back();
                visited[i] = false;
            }
        }
    }
};
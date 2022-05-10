class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        vector<vector<int>> ans;
        helper(k, n, t, ans);
        return ans;
    }
private:
    void helper(int k, int n, vector<int>& tmp, vector<vector<int>>& ans) {
        if(k < 0 || n < 0) return;
        if (k == 0 && n == 0) {
            ans.push_back(tmp);
            return;
        }
        int start = tmp.empty() ? 1 : tmp.back() + 1;
        for (int i=start; i>=1 && i <=9 && i<=n; ++i) {
            tmp.push_back(i);
            helper(k-1, n-i, tmp, ans);
            tmp.pop_back();
        }
    }
};
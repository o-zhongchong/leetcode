class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<pair<int,int>> w;
        for(int i=0; i<m; ++i) {
            pair<int,int> t;
            t.first = i;
            t.second = 0;
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1) {
                    ++t.second;
                } else {
                    break;
                }
            }
            w.push_back(t);
        }
        auto cmp = [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second < b.second || 
                   (a.second == b.second && a.first < b.first);
        };
        sort(w.begin(), w.end(), cmp);
        vector<int> ans;
        for(int i=0; i<k; ++i) {
            ans.push_back(w[i].first);
        }
        return ans;
    }
};
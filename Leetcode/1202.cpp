class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> ds(n, 0);
        for(int i=0; i<n; ++i) ds[i] = i;
        for(auto pair : pairs) {
            int fx = find(ds, pair[0]);
            int fy = find(ds, pair[1]);
            if(fx != fy) ds[fx] = fy;
        }
        vector<vector<int>> g(n, vector<int>());
        for(int i=0; i<n; ++i) {
            int idx = find(ds, i);
            g[idx].push_back(i);
        }
        for(int i=0; i<n; ++i) {
            int len = g[i].size();
            string t = "";
            for(int j=0; j<len; ++j) {
                t.push_back(s[g[i][j]]);
            }
            sort(t.begin(), t.end());
            for(int j=0; j<len; ++j) {
               s[g[i][j]] = t[j]; 
            }
        }
        return s;
    }
private:
    int find(vector<int> &ds, int x) {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
};
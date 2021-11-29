class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> emails;
        unordered_map<int,string> names;
        unordered_map<int,int> m;
        int len = accounts.size();
        vector<int> ds(len, 0);
        for(int i=0; i<len; ++i) {
            ds[i] = i;
        }
        for(int i=0; i<len; ++i) {
            names[i] = accounts[i][0];
            int cnt = accounts[i].size();
            for(int j=1; j<cnt; ++j) {
                if(emails.count(accounts[i][j])) {
                    merge(ds, i, emails[accounts[i][j]]);
                    continue;
                }
                emails[accounts[i][j]] = i;
            }
        }
        int total = 0;
        for(int i=0; i<len; ++i) {
            if(ds[i] == i) {
                m[i] = total++;
            }
        }
        vector<vector<string>> ret(total);
        for(auto em : emails) {
            int id = find(ds, em.second);
            ret[m[id]].push_back(em.first);
        }
        for(int i=0; i<total; ++i) {
            sort(ret[i].begin(), ret[i].end());
            int id = find(ds, emails[ret[i][0]]);
            ret[i].insert(ret[i].begin(), names[id]);
        }
        return ret;
    }
private:
    int find(vector<int> &ds, int x) {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    int merge(vector<int> &ds, int x, int y) {
        int fx = find(ds, x);
        int fy = find(ds, y);
        if(fx != fy) {
            ds[fx] = fy;
            return 1;
        }
        return 0;
    }
};
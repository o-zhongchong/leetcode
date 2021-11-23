class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int len = nums.size();
        vector<int> ds(len, 0);
        unordered_map<int,int> m;
        unordered_map<int,int> cnt;
        int mx = 0;
        for(int i=0; i<len; ++i) {
            ds[i] = i;
        }
        for(int i=0; i<len; ++i) {
            m.count(nums[i]) ? merge(ds, i, m[nums[i]]) : m[nums[i]] = i;
            for(int d=sqrt(nums[i]); d>=2; --d) {
                if(nums[i] % d == 0) {
                    m.count(d) ? merge(ds,i,m[d]) : m[d] = i;
                    m.count(nums[i]/d) ? merge(ds,i,m[nums[i]/d]) : m[nums[i]/d]=i;
                }
            }
        }
        for(int i=0; i<len; ++i) {
            int fi = find(ds,i);
            mx = max(mx, ++cnt[fi]);
        }
        return mx;
    }
private:
    int find(vector<int>& ds, int x) {
        return ds[x] == x ? x : ds[x] = find(ds, ds[x]);
    }
    int merge(vector<int>& ds, int x, int y) {
        int fx = find(ds, x);
        int fy = find(ds, y);
        if(fx != fy) {
            ds[fx] = fy;
            return 1;
        }
        return 0;
    }
};
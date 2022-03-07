class Solution {
public:
    typedef pair<int,int> node;
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto cmp = [](const node &a, const node &b){
            return a.first < b.first;
        };
        vector<node> arr;
        for(auto n : nums) {
            int t = transform(mapping, n);
            arr.push_back(make_pair(t,n));
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<int> ans;
        for(auto n : arr) {
            ans.push_back(n.second);
        }
        return ans;
    }
private:
    int transform(vector<int> &m, int n) {
        int ans = 0, w = 1;
        if(n == 0) return m[0];
        while(n) {
            int idx = n % 10;
            ans += w * m[idx];
            n /= 10;
            w *= 10;
        }
        return ans;
    }
};
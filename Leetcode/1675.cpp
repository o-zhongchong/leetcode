class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        auto cmp = [](const int &a, const int &b){
            return a < b;
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        int lo = INT_MAX;
        for(auto n : nums) {
            if(n & 1) n <<= 1;
            pq.push(n);
            lo = min(lo, n);
        }
        int ans = pq.top() - lo;
        while(pq.top() % 2 == 0) {
            int t = pq.top(); pq.pop();
            pq.push(t/2);
            lo = min(lo, t/2);
            ans = min(ans, pq.top() - lo);
        }
        return ans;
    }
};
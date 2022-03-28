class Solution {
public:
    int halveArray(vector<int>& nums) {
        auto cmp = [](const double &a, const double &b) {
            return a < b;
        };
        priority_queue<double,vector<double>,decltype(cmp)> pq(cmp);
        int len = nums.size();
        double sum = 0.0, reduce = 0.0;
        for(int i=0; i<len; ++i) {
            sum += (double)nums[i];
            pq.push((double)nums[i]);
        }
        sum /= 2;
        int ans = 0;
        while(reduce < sum) {
            double t = pq.top() / 2; pq.pop();
            reduce += t;
            pq.push(t);
            ++ans;
        }
        return ans;
    }
};
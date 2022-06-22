class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](const int& a, const int& b) {
            return a > b;
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        for (auto& n: nums) {
            pq.push(n);
            while(pq.size() > k) pq.pop();
        }
        return pq.empty() ? -1 : pq.top();
    }
};
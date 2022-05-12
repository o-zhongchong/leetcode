class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto cmp1 = [](const int& a, const int& b) {
            return a < b;
        };
        auto cmp2 = [](const int& a, const int& b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp1)> pq1(cmp1);
        priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);
        vector<int> nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        for (auto n : nums) {
            if (pq1.size() == pq2.size()) {
                pq2.push(n);
                int t = pq2.top(); pq2.pop();
                pq1.push(t);
            } else {
                pq1.push(n);
                int t = pq1.top(); pq1.pop();
                pq2.push(t);
            }
        }
        if (pq1.size() == pq2.size()) {
            return (double)(pq1.top() + pq2.top()) / 2.0;
        }
        return pq1.top();
    }
};
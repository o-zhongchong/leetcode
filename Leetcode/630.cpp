class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];    
        };
        int len = courses.size();
        priority_queue<int, vector<int>, less<int>> pq;
        sort(courses.begin(), courses.end(), cmp);
        int total = 0;
        for (int i=0; i<len; ++i) {
            total += courses[i][0];
            pq.push(courses[i][0]);
            if (total > courses[i][1]) {
                total -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
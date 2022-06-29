class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(people.begin(), people.end(), cmp);
        int len = people.size();
        for (int i=0; i<len; ++i) {
            if (people[i][1] != i) {
                int pos = people[i][1];
                for (int j=i; j>pos; --j) {
                    swap(people[j], people[j-1]);
                }
            }
        }
        return people;
    }
};
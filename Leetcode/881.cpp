class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size();
        sort(people.begin(),people.end());
        int left = 0, right = len-1;
        int ret = 0;
        while(left <= right) {
            if(left < right && limit - people[right] >= people[left]) {
                ++left;
            }
            --right;
            ++ret;
        }
        return ret;
    }
};
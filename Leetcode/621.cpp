#include <queue>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        
        for(auto c : tasks)
        {
            ++cnt[c - 'A'];
        }
        
        sort(cnt.begin(), cnt.end());
        int i = 25;
        int mx = cnt[25];
        int len = tasks.size();
        
        while(i >=0 && cnt[i] == mx)
        {
            --i;
        }
        
        return max(len, (n + 1) * (mx - 1) + 25 - i);
    }
};
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int len = text.size();
        vector<int> pos1,pos2;
        for(int i=0; i<len; ++i) {
            if(text[i] == pattern[0]) {
                pos1.push_back(i);
            } else if(text[i] == pattern[1]) {
                pos2.push_back(i);
            }
        }
        if(pattern[0] == pattern[1]) {
            long long ans = 0;
            long long sz = pos1.size();
            if(sz > 1) {
                ans += sz * (sz-1) / 2;
            }
            ans += sz;
            return ans;
        }
        long long sz1 = pos1.size(), sz2 = pos2.size();
        long long ans = 0;
        for(int i=0, j=0; i<sz1; ++i) {
            while(j < sz2 && pos1[i] >= pos2[j]) {
                ++j;
            }
            if(j < sz2) ans += sz2 - j;
        }
        ans += max(sz1, sz2);
        return ans;
    }
};
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int len = beans.size();
        vector<long long> prefix,suffix;
        prefix = suffix = vector<long long>(len, 0);
        for(int i=1, j=1; i<len; ++i) {
            if(beans[i] == beans[i-1]) {
                ++j;
                prefix[i] = prefix[i-1];
            } else {
                prefix[i] = prefix[i-1] + (long long)beans[i-1] * (long long)j;
                j = 1;
            }
        }
        for(int i=len-2; i>=0; --i) {
            if(beans[i] == beans[i+1]) {
                suffix[i] = suffix[i+1];
            } else {
                suffix[i] = (long long)(beans[i+1]-beans[i])*(long long)(len-1-i) + suffix[i+1];
            }
        }
        long long ans = 0;
        for(auto b : beans) ans += b;
        for(int i=0; i<len; ++i) {
            ans = min(ans, prefix[i]+suffix[i]);
        }
        return ans;
    }
};
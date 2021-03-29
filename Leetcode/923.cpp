class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int len = arr.size();
        unordered_map<int, int> cnt;
        int ret = 0;
        int M = 1e9 + 7;
        
        for(int i=0; i<len; ++i)
        {
            ret = (ret + cnt[target - arr[i]]) % M;
            
            for(int j=0; j<i; ++j)
            {
                ++cnt[arr[j] + arr[i]];
            }
        }
        
        return ret;
    }
};
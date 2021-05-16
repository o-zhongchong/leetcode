class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int len = nums.size();
        const int M = 1e9 + 7;
        int *pfx = new int[100001];
        memset(pfx, 0, 100001);
        int max_n = INT_MIN;
        unordered_map<int,int> freq;
        vector<int> uniq;
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            ++freq[nums[i]];
            max_n = max(max_n, nums[i]);
        }
        
        for(int i=1; i<=max_n; ++i)
        {
            if(freq.count(i))
            {
                uniq.push_back(i);
                pfx[i] = freq[i];
            }
            
            pfx[i] += pfx[i-1];
        }
        
        for(auto n : uniq)
        {
            for(int i=max_n/n; i>0; --i)
            {
                int L = n * i - 1;
                int R = min(max_n, n*(i+1)-1);
                ret = (ret + freq[n] * i * (pfx[R] - pfx[L])) % M;
            }
        }
        
        return ret;
    }
};
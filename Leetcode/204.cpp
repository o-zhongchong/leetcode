class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1, 1);
        int cnt = 0;
        
        for(int i=2; i<n; ++i)
        {
            if(primes[i] == 1)
            {
                ++cnt;
                
                for(int j=2; j * i < n; ++j)
                {
                    primes[i*j] = 0;
                }
            }
        }
        
        return cnt;
    }
};

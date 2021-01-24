class Solution {
public:
    int makePrime(vector<int>& prime, int maxN)
    {
        //if i is prime then prime[i] == i
        for(int i=0; i<maxN; ++i)
        {
            prime[i] = i;
        }
        
        //if i is not prime, prime[i] is the smallest prime factor of i
        for(int i=2; i<maxN; ++i)
        {
            int j = i * i;
            
            while(prime[i] == i && j < maxN)
            {
                if(prime[j] == j)
                {
                    prime[j] = i;
                }
                
                j += i;
            }
        }
        
        return 0;
    }
    
    vector<int> getFactors(vector<int>& prime, int x)
    {
        //return all prime factors of x
        vector<int> ret;
        unordered_map<int, int> factors;
        
        while(x > 1)
        {
            ++factors[prime[x]];
            x /= prime[x];
        }
        
        for(auto i : factors)
        {
            ret.push_back(i.second);
        }
        
        return ret;
    }
    
    int makeComb(vector<vector<long long>>& chooser, int m, int n, int mod)
    {
        for(int i=0; i<m; ++i)
        {
            chooser[i][0] = 1;
        }
        
        for (int i=1; i<m; ++i)
        {
            for (int j=1; j<n; ++j)
            {
                chooser[i][j] = (chooser[i-1][j-1] + chooser[i-1][j]) % mod;
            }
        }
        
        return 0;
    }
    
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        int len = queries.size();
        int maxN = 10001, mod = 1e9 + 7;
        vector<vector<long long>> chooser(maxN+33, vector<long long>(33, 0));
        vector<int> prime(maxN, 1);
        vector<int> ret;
        makePrime(prime, maxN);
        makeComb(chooser, maxN+33, 33, mod);
        
        for(int i=0; i<len; ++i)
        {
            int n = queries[i][0];
            int k = queries[i][1];
            long long count = 1;
            
            vector<int> factors = getFactors(prime, k);
            
            for(auto j : factors)
            {
                count = (count * chooser[n+j-1][j]) % mod;
            }
            
            ret.push_back((int)count);
        }
        
        return ret;
    }
};
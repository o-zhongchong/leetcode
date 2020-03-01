class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 )
            return 0;
        
        int* isPrimes = new int[n];
        int cnt = 0;
        
        isPrimes[0] = 0;
        isPrimes[1] = 0;
        isPrimes[2] = 1;
        
        for(int i=3; i<n; ++i)
        {
            isPrimes[i]=1;
        }
        
        for(int i=2; i<n; ++i)
        {
            int j = 2;
            while(i*j < n)
            {
                isPrimes[i*j] = 0;
                ++j;
            }
        }
        
        for(int i=2; i<n; ++i)
        {
            if(1 == isPrimes[i])
                ++cnt;
        }
        
        return cnt;
    }
};
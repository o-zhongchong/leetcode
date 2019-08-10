class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int len = A.size();
        if( len <= 0)
            return 0;
        
        int min, max;
        min = max = A[0];
        for( auto &i: A)
        {
            if( i>max )
                max=i;
            if( i<min)
                min=i;
        }
        
        if( max - min > 2*K )
            return max - min - 2*K;
        return 0;
    }
};
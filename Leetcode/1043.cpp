class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if( A.empty() || K<=0 )
            return -1;
        
        vector<int> ret;
        ret.push_back(A[0]);
        
        int length = A.size();
        for(int i=1; i<length; ++i)
        {
            ret.push_back(ret[i-1] + A[i]);
            int max_num = A[i];
            
            for(int j=1; j<K; ++j)
            {
                if( i-j >= 0 )
                {
                    if( A[i-j] > max_num)
                        max_num = A[i-j];
                    int sum = max_num * (j+1);
                    
                    if(i-j-1 >=0 )
                        sum += ret[i-j-1];
                    
                    if( sum > ret[i])
                        ret[i] = sum;
                }
            }
        }
        return ret[length-1];
    }
};
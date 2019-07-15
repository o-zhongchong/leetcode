class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if( A.size() < 3 )
            return -1;
        
        int ret=0, flag=true;
        
        for(unsigned int i=1; i<A.size(); ++i)
        {
            if( flag )
            {
                if( A[i] > A[i-1] )
                    ret = i;
                else if( A[i] < A[i-1] )
                    flag = false;
                else
                    return -1;
            }
            else
            {
                if( A[i] < A[i-1] )
                    continue;
                else
                    return -1;
            } 
        }
        
        if( ret )
            return ret;
        
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)     {
        vector<vector<int>> ret;
        
        if( A.empty() || B.empty() )
            return ret;
        
        int len_A = A.size();
        int len_B = B.size();
        int i=0, j=0;
        
        while( i<len_A && j<len_B )
        {
            int low = max(A[i][0],B[j][0]);
            int high = min(A[i][1],B[j][1]);
            
            if( low<=high)
            {
                vector<int> interval = {low,high};
                ret.push_back(interval);
            }
            
            if( high == A[i][1] )
                ++i;
            else
                ++j;
        }
        
        return ret;
    }
};
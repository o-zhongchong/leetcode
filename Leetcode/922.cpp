class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        unsigned int i=0,  j=1;
        while (i < A.size() && j < A.size())
        {
            if ( (A[i] & 1) && !(A[j] & 1) )
            {
                swap(A[i], A[j]);
                i = i + 2;
                j = j + 2;
            }
            else if ( !(A[i] & 1) && (A[j] & 1) )
            {
                i = i + 2;
                j = j + 2;
            }
            else if ( (A[i] & 1) && (A[j] & 1) )
            {
                j = j + 2;
            }
            else if ( !(A[i] & 1) && !(A[j] & 1) )
                i = i + 2;
        }
        return A;
    }
};
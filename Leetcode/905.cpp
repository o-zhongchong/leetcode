class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int s=0, e=A.size()-1;
        int tmp;
        while(s != e)
        {
            if( A[s] & 1)
            {
                tmp = A[s];
                A[s] = A[e];
                A[e] = tmp;
                --e;
                continue;
            }
            else
                ++s;
        }
        vector<int> B(A);
        return B;
    }
};
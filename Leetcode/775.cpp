class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int len = A.size();
        int min_num = INT_MAX;
        
        for(int i=len-1; i>=2; --i)
        {
            min_num = min(min_num, A[i]);
            
            if(A[i-2] > min_num)
            {
                return false;
            }
        }
        
        return true;
    }
};
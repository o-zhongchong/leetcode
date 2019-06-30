#include<unordered_set>

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> A_set;
        for(int i=0; i<A.size(); ++i)
        {
            if(A_set.count(A[i]))
                return A[i];
            else
                A_set.insert(A[i]);
        }
        return -1;
    }
};
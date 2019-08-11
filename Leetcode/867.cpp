class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ret;
        vector<vector<int>>::size_type R = A.size();
        
        if( R == 0)
            return ret;
        vector<int>::size_type C = A[0].size();
        
        for(vector<int>::size_type i=0; i < C; ++i)
        {
            vector<int> trans;
            for(vector<vector<int>>::size_type j=0; j<R; ++j)
            {
                trans.push_back(A[j][i]);
            }
            ret.push_back(trans);
        }
        return ret;
    }
};
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if ( A.empty() )
            return -1;

        unsigned int len = A[0].size();

        for (auto s : A)
            if (s.size() != len)
                return -1;

        int ret = 0;
        for (unsigned int i = 0; i < len; ++i)
        {
            for (unsigned int j = 1; j < A.size(); ++j)
            {
                if (A[j][i] < A[j - 1][i])
                {
                    ++ret;
                    break;
                }
            }
        }

        return ret;
    }
};
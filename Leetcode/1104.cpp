class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        if ( !(label >= 1 && label <= 1000000) )
            return result;

        int N = floor( log(label) / log(2) ) + 1 ;
        int curr = label;

        if (1 == N)
        {
            result.insert(result.begin(), 1);
            return result;
        }

        for (int i = N; i > 1; --i )
        {
            result.insert(result.begin(), curr);
            if (i & 1)
            {
                int seq = pow(2, i - 2) - 1;
                curr = pow(2, i - 2) - (floor(curr / 2) - seq) + 1 + seq;
            }
            else
            {
                int seq = pow(2, i - 1) - 1;
                seq = seq + pow(2, i - 1) - (curr - seq) + 1;
                curr = floor(seq / 2);
            }
        }
        result.insert(result.begin(), 1);

        return result;
    }
};
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        if (A.size() <= 0)
            return -1;

        unordered_map<int, int> unique;
        int ret = -1;

        for (auto &i : A)
        {
            auto search = unique.find(i);
            if ( search == unique.end() )
                unique.insert( make_pair(i, 1) );
            else
                ++search->second;
        }

        for (auto &i : unique)
        {
            if ( i.second > 1 )
                continue;
            else
            {
                if (i.first > ret)
                    ret = i.first;
            }
        }
        return ret;
    }
};
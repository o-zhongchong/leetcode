#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int index[26];
        vector<int> res;

        for (int i = 0; i < S.length(); ++i)
            index[S.at(i) - 'a']  = i;

        int start, end;
        start = end = 0;
        for (int i = 0; i < S.length(); ++i)
        {
            if ( index[S.at(i) - 'a'] > end )
                end = index[S.at(i) - 'a'];
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end = i + 1;
            }
        }
        return res;
    }
};
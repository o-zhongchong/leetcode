class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0, even=0;
        int len = position.size();
        for(int i=0; i<len; ++i) {
            position[i] & 1 ? ++odd : ++even;
        }
        return min(even, odd);
    }
};
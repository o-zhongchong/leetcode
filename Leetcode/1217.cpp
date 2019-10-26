class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int len = chips.size();
        int x = 0;
        for(auto i : chips)
        {
            x += i%2;
        }
        return min(x,len-x);
    }
};

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> order = heights;
        int ret = 0;
        sort(order.begin(), order.end() );
        for(unsigned int i=0; i < heights.size(); ++i )
            if( order[i] != heights[i])
                ++ret;
        return ret;
    }
};
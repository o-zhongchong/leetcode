class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for(auto point : ghosts) {
            if(abs(point[0]-target[0]) + abs(point[1]-target[1]) <= dist) {
                return false;
            }
        }
        return true;
    }
};
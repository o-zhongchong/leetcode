class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> type;
        
        for(auto &t : candyType)
        {
            type.insert(t);
        }
        
        int totalType = type.size();
        
        return n/2 < totalType ? n/2 : totalType;
    }
};
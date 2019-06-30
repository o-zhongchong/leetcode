class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int low=0, high=S.size();
        
        for( auto ch:S)
        {
            if( ch == 'I' )
            {
                res.push_back(low);
                ++low;
            }
            else if( ch == 'D' )
            {
                res.push_back(high);
                --high;
            }
            else
                res.push_back(-1);
        }
        res.push_back(low);
        return res;
    }
};
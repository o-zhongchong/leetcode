class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ret;
        if( seq.empty() )
            return ret;
        
        int cnt=0;
        for( auto &c : seq )
        {
            if( c == '(' )
            {
                ++cnt;
                if( cnt & 1 )
                    ret.push_back(0);
                else
                    ret.push_back(1);
            }
            else if( c == ')' )
            {
                if( cnt & 1 )
                    ret.push_back(0);
                else
                    ret.push_back(1);
                --cnt;
            }
            else
            {
                vector<int> err;
                return err;
            }
        }
        return ret;
    }
};
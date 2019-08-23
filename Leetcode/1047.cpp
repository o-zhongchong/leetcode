class Solution {
public:
    string removeDuplicates(string S) {
        string ret;
        
        if( S.empty() )
            return ret;

        int len = S.size();
        for( int i=0; i<len; ++i)
        {
            if( !ret.empty() && ret.back() == S[i] )
            {
                ret.pop_back();
            }
            else
                ret.push_back(S[i]);
        }
        return ret;
    }
};
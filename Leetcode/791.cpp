class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> dict;
        
        int len = S.size();
        for(int i=0; i<len; ++i)
        {
            dict.insert( make_pair(S[i],i) );
        }
        
        len = T.size();
        for(int i=len-1; i>0; --i)
        {
            for(int j=0; j<i; ++j)
            {
                auto s1 = dict.find(T[j]);
                auto s2 = dict.find(T[j+1]);
                
                if( s1 == dict.end() )
                    continue;
                else
                {
                    if( s2 == dict.end() || s1->second > s2->second)
                        swap(T[j],T[j+1]);
                    else
                        continue;
                }
            }
        }
        
        return T;
    }
};
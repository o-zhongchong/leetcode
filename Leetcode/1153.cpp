class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2)
            return true;
        
        vector<int> trans;
        for(int i=0; i<26; ++i)
            trans.push_back(-1);
        
        int len = str1.size();
        for(int i=0;i<len;++i)
        {
            int s1 = str1[i] - 'a';
            int s2 = str2[i] - 'a';
            
            if( trans[s1] == -1 )
            {
                trans[s1] = s2;
                continue;
            }
            else
            {
                if( trans[s1] != s2)
                    return false;
            }
        }
        
        bitset<26> b_map;
        int cnt = 0;
        for( auto &c: str2)
        {
            cnt += !b_map[c-'a'];
            if(cnt == 26)
                return false;
            b_map[c-'a']=1;
        }
        return true;
    }
};
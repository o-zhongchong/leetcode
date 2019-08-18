class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if( words.empty() || chars.empty() )
            return -1;
        
        unordered_map<char,int> dict;
        for( auto &c: chars)
        {
            auto search = dict.find(c);
            if( search == dict.end() )
                dict.insert( make_pair(c,1) );
            else
                ++search->second;
        }
        
        int ret = 0;
        unordered_map<char,int> char_cnt;
        for( auto &str : words )
        {
            bool chk = true;
            char_cnt.clear();
            for( auto &i : str)
            {
                auto search = dict.find(i);
                if( search == dict.end() )
                {
                    chk = false;
                    break;
                }
                else
                {
                    auto search2 = char_cnt.find(i);
                    if( search2 == char_cnt.end() )
                        char_cnt[i]=1;
                    else
                        ++search2->second;
                    
                    if( char_cnt[i] > dict[i] )
                    {
                        chk = false;
                        break;
                    }
                }
            }
            
            if(chk)
            {
                ret += str.size();
            }
        }
        return ret;
    }
};
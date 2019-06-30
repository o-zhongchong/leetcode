class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> pattern_dict, word_dict;
        vector<string> res;

        for( auto word:words )
        {
            if( word.size() != pattern.size() )
                continue;
            pattern_dict.clear();
            word_dict.clear();
            int check_result = 1;
            
            for(int i=0; i<word.size(); ++i)
            {
                if( pattern_dict.find(pattern[i]) == pattern_dict.end() 
                  && word_dict.find(word[i]) == word_dict.end() )
                {
                    pattern_dict[pattern[i]] = word[i];
                    word_dict[word[i]] = pattern[i];
                }
                else if(pattern_dict.find(pattern[i]) != pattern_dict.end() 
                  && word_dict.find(word[i]) != word_dict.end())
                {
                    if(pattern_dict[pattern[i]] == word[i] 
                      && word_dict[word[i]] == pattern[i] )
                        continue;
                    else
                    {
                        check_result = 0;
                        break;
                    }
                }
                else
                {
                    check_result = 0;
                    break;
                }
            }
            
            if(check_result == 1)
                res.push_back(word);
        }
        return res;
    }
};
class Solution {
public:
    string reorderSpaces(string text) {
        int space_cnt = 0;
        int word_cnt = 0;
        bool is_word = false;
        int len = text.size();
        string ret;
        
        for(auto c : text)
        {
            if(c == ' ')
            {
                ++space_cnt;
                is_word = false;
            }
            else
            {
                if(!is_word)
                {
                    is_word = true;
                    ++word_cnt;
                }
            }
        }
        
        int space_len = 0;
        int space_used = 0;
        is_word = false;
        
        if(word_cnt - 1 != 0)
        {
            space_len = space_cnt / (word_cnt - 1);
        }
        
        for(auto c : text)
        {
            if(c == ' ' && is_word)
            {
                if(space_used + space_len <= space_cnt)
                {
                    ret += string(space_len, ' ');
                    space_used += space_len;
                }
                else
                {
                    ret += string(space_cnt - space_used, ' ');
                    space_used += space_cnt - space_used;
                }
                
                is_word = false;
            }
            
            if(c != ' ')
            {
                if(!is_word)
                {
                    is_word = true;
                }
                
                ret.push_back(c);
            }
        }
        
        if(space_cnt - space_used > 0)
        {
            ret += string(space_cnt - space_used, ' ');
        }
        
        return ret;
    }
};
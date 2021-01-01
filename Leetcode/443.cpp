class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
        {
            return 0;
        }
        
        int len = chars.size();
        int new_length = 0, cnt = 0;
        char ch;
        
        for(int i=0; i<len; ++i)
        {
            if(cnt == 0)
            {
                ch = chars[i];
                ++cnt;
            }
            else
            {
                if(chars[i] == ch)
                {
                    ++cnt;
                }
                else
                {
                    chars[new_length++] = ch;
                    
                    if(cnt > 1)
                    {
                        string s = to_string(cnt);
                    
                        for(char k : s)
                        {
                            chars[new_length++] = k;
                        }
                    }
                    
                    ch = chars[i];
                    cnt = 1;
                }
            }
        }
        
        if(cnt > 0)
        {
            chars[new_length++] = ch;
            
            if(cnt > 1)
            {
                string s = to_string(cnt);

                for(char k : s)
                {
                    chars[new_length++] = k;
                }
            }
        }
        
        chars.resize(new_length);
        return new_length;
    }
};
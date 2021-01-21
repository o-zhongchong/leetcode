class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int len = source.size();
        vector<string> ret;
        int comment = 0;
        string str;
        
        for(int i=0; i<len; ++i)
        {
            int len2 = source[i].size();
            
            for(int j=0, k=0; j<len2; ++j)
            {
                if(comment == 0 && source[i][j] == '/' &&
                   j + 1 < len2 && source[i][j+1] == '/')
                {
                    str += source[i].substr(k, j-k);
                    break;
                }
                
                if(comment == 0 && source[i][j] == '/' &&
                   j + 1 < len2 && source[i][j+1] == '*')
                {
                    str += source[i].substr(k, j-k);
                    comment = 1;
                    ++j;
                    continue;
                }
                
                if(comment == 1 && source[i][j] == '*' &&
                   j + 1 < len2 && source[i][j+1] == '/')
                {
                    comment = 0;
                    ++j;
                    k = j + 1;
                    continue;
                }
                
                if(comment == 0 && j == len2 - 1)
                {
                    str += source[i].substr(k, len2-k);
                }
            }
            
            if(comment == 0 && str.size() > 0)
            {
                ret.push_back(str);
                str = "";
            }
        }
        
        return ret;
    }
};
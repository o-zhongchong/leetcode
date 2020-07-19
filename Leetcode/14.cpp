class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if(0 == num)
            return "";
        
        int min_len = strs[0].size();
        for(int i=1; i<num; ++i)
        {
            int len = strs[i].size();
            if(len < min_len)
                min_len = len;
        }
        
        for(int i=min_len; i>0; --i)
        {
            string prefix = strs[0].substr(0, i);
            bool is_common = true;
            
            for(int j=0; j<num; ++j)
            {
                if(strs[j].substr(0, i) != prefix)
                {
                    is_common = false;
                    break;
                }
            }
            
            if( is_common )
                return prefix;
        }
        
        return "";
    }
};
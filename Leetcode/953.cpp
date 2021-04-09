class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> dict;
        int len = order.size();
        
        for(int i=0; i<len; ++i)
        {
            dict[order[i]] = i;
        }
        
        int sz = words.size();
        
        for(int i=1; i<sz; ++i)
        {
            int len1 = words[i-1].size();
            int len2 = words[i].size();
            
            for(int j=0, k=0; j<len1 && k <len2; ++j, ++k)
            {
                char c1 = words[i-1][j];
                char c2 = words[i][k];
                
                if(dict[c1] < dict[c2])
                {
                    break;
                }
                else if(dict[c1] > dict[c2])
                {
                    return false;
                }
                
                if(len1 > len2 && j == len2-1 && dict[c1] == dict[c2])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
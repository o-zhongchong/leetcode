class Solution {
public:
    string toLowerCase(string str)
    {
        int len = str.size();
        
        for(int i=0; i<len; ++i)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] - 'A' + 'a';
            }
        }
        
        return str;
    }
    
    string getKey(string str)
    {
        int len = str.size();
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        
        for(int i=0; i<len; ++i)
        {
            if(vowel.count(str[i]))
            {
                str[i] = 'a';
            }
        }
        
        return str;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int len1 = wordlist.size();
        int len2 = queries.size();
        vector<string> ret(len2, "");
        unordered_set<string> set1;
        unordered_map<string, string> map1;
        unordered_map<string, string> map2;
        
        for(int i=0; i<len1; ++i)
        {
            set1.insert(wordlist[i]);
            string key = toLowerCase(wordlist[i]);
            
            if(!map1.count(key))
            {
                map1[key] = wordlist[i];
            }
            
            key = getKey(key);
            
            if(!map2.count(key))
            {
                map2[key] = wordlist[i];
            }
        }
        
        for(int i=0; i<len2; ++i)
        {
            string key1 = toLowerCase(queries[i]);
            string key2 = getKey(key1);
            
            if(set1.count(queries[i]))
            {
                ret[i] = queries[i];
            }
            else if(map1.count(key1))
            {
                ret[i] = map1[key1];
            }
            else if(map2.count(key2))
            {
                ret[i] = map2[key2];
            }
        }
        
        return ret;
    }
};
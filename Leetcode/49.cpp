class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> mymap;
        
        for(auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            
            if(mymap.find(key) != mymap.end())
            {
                int i = mymap[key];
                ret[i].push_back(str);
            }
            else
            {
                ret.push_back(vector<string>(1, str));
                int i = ret.size() - 1;
                mymap[key] = i;
            }
        }
        
        return ret;
    }
};
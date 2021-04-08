class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.size();
        vector<string> ret;
        
        for(int i=0; i<len; ++i)
        {
            string str = dict[digits[i] - '2'];
            vector<string> tmp;
            
            for(auto &c: str)
            {
                if(ret.empty())
                {
                    tmp.push_back(string(1, c));
                }
                else
                {
                    for(auto &s: ret)
                    {
                        tmp.push_back(s + string(1, c));
                    }
                }
            }
            
            ret = tmp;
        }
        
        return ret;
    }
};
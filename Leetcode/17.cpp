class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string s;
        
        if( digits.empty() )
            return ret;
        
        genLetter(digits, 0, s, ret);
        return ret;
    }
    
    int genLetter(string &digits, int i, string s, vector<string> &v)
    {
        if(i == digits.size() )
        {
            v.push_back(s);
            return 0;
        }
        
        string dict[8] = {"abc","def", "ghi", "jkl",
                       "mno","pqrs","tuv","wxyz"};
        int n = digits[i] - '2';
        for( auto c : dict[n] )
        {
            s.push_back(c);
            genLetter(digits, i+1, s, v);
            s.pop_back();
        }
        
        return 0;
    }
};
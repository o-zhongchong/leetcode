class Solution {
public:
    static bool comp(const string &a, const string& b)
    {
        return a.size() > b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        string reference;
        sort(words.begin(), words.end(), comp);
        
        for(auto &word: words)
        {
            if(reference.find(word + "#") == reference.npos)
            {
                reference += word + "#";
            }
        }
        
        return reference.size();
    }
};
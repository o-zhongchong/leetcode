class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        string temp_str="";
        int length = characters.size();
        helper(characters, length, 0, temp_str, combinationLength);
        cur_index=0;
    }
    
    string next() {
        int length = combination_str.size();
        string ret;
        if(cur_index < length)
        {
            ret = combination_str[cur_index];
            ++cur_index;
        }
        return ret;
    }
    
    bool hasNext() {
        int length = combination_str.size();
        if(cur_index < length)
            return true;
        return false;
    }
protected:
    vector<string> combination_str;
    int cur_index;
    
    int helper(string &characters, int length, int index, string &temp_str, int             combinationLength)
    {
        if(temp_str.size() == combinationLength)
        {
            combination_str.push_back(temp_str);
            return 0;
        }
        for(int i=index; i<length; ++i)
        {
            temp_str.push_back(characters[i]);
            helper(characters, length, i+1, temp_str, combinationLength);
            temp_str.pop_back();
        }
        return 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        int len = characters.size();
        vector<bool> visited(len,false);
        string t = "";
        helper(characters, combinationLength, t, 0);
    }
    string next() {
        string r = mDat.front();
        mDat.pop();
        return r;
    }
    bool hasNext() {
        return !mDat.empty();
    }
private:
    void helper(string &str, int length, string &ret, int pos) {
        if(str.size() - pos + ret.size() < length) {
            return;
        }
        if(ret.size() == length) {
            mDat.push(ret);
            return;
        }
        int len = str.size();
        for(int i=pos; i<len; ++i) {
            ret.push_back(str[i]);
            helper(str, length, ret, i+1);
            ret.pop_back();
        }
    }
private:
    queue<string> mDat;
};

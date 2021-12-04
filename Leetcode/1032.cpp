/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
class Trie {
public:
    Trie() {
        for(int i=0; i<26; ++i) {
            next[i] = nullptr;
        }
        isWord = false;
    }
    static void addWord(Trie* root, string &word) {
        int len = word.size();
        for(int i=len-1; i>=0; --i) {
            int idx = word[i] - 'a';
            if(!root->next[idx]) {
                Trie* p = new Trie();
                root->next[idx] = p;
            }
            root = root->next[idx];
        }
        root->isWord = true;
    }
public:
    bool isWord;
    Trie* next[26];
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(string &word: words) {
            Trie::addWord(root, word);
        }
    }
    bool query(char letter) {
        queryStr.push_back(letter);
        int len = queryStr.size();
        Trie* p = root;
        for(int i=len-1; i>=0; --i) {
            int idx = queryStr[i] - 'a';
            if(!p->next[idx]) {
                return false;
            }
            p = p->next[idx];
            if(p->isWord) {
                return true;
            }
        }
        return false;
    }
private:
    Trie* root;
    string queryStr;
};

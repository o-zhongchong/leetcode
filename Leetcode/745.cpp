/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
class Trie {
public:
    Trie(int idx = -1):index(idx), child(27, nullptr) {}
public:
    static void insert(Trie* root, string& w, int idx) {
        for (char c : w) {
            if (root->child[c - 'a'] == nullptr) {
                root->child[c - 'a'] = new Trie();
            }
            root = root->child[c - 'a'];
            root->index = max(root->index, idx);
        }
        root->index = max(root->index, idx);
    }
    static int query(Trie* root, string& key) {
        for (char c : key) {
            if (root->child[c - 'a'] == nullptr) return -1;
            root = root->child[c - 'a'];
        }
        return root->index;
    }
private:
    vector<Trie*> child;
    int index;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int len = words.size();
        for (int i=0; i<len; ++i) {
            auto key = "{" + words[i];
            Trie::insert(&root, key, i);
            int cnt = words[i].size();
            for (int j=cnt-1; j>=0; --j) {
                key = words[i][j] + key;
                Trie::insert(&root, key, i);
            }
        }
    }
    int f(string prefix, string suffix) {
        auto key = suffix + "{" + prefix;
        return Trie::query(&root, key);
    }
private:
    Trie root;
    vector<string> words;
};

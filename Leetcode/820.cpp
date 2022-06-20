class Trie {
public:
    Trie():child(26, nullptr), word(false) {}
public:
    static void insert(Trie* root, string& str) {
        int len = str.size();
        for (int i=len-1; i>=0; --i) {
            char c = str[i];
            if (root->child[c - 'a'] == nullptr) {
                root->child[c - 'a'] = new Trie();
            }
            root = root->child[c - 'a'];
        }
        root->word = true;
    }
    static bool query(Trie* root, string& str) {
        int len = str.size();
        for (int i=len-1; i>=0; --i) {
            char c = str[i];
            if (root->child[c - 'a'] == nullptr) return false;
            root = root->child[c - 'a'];
        }
        return true;
    }
private:
    vector<Trie*> child;
    bool word;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto cmp = [](const string& a, const string& b) {
            return a.size() > b.size();
        };
        sort(words.begin(), words.end(), cmp);
        int ans = 0;
        Trie root;
        for (auto& w : words) {
            if(!Trie::query(&root, w)) {
                ans += w.size() + 1;
                Trie::insert(&root, w);
            }
        }
        return ans;
    }
};
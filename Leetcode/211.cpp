struct TrieNode
{
    int isExist;
    struct TrieNode* next[26];
    TrieNode():isExist(0)
    {
        for(int i=0; i<26; ++i)
        {
            next[i] = nullptr;
        }
    }
    ~TrieNode()
    {
        for(int i=0; i<26; ++i)
        {
            if(next[i] != nullptr)
            {
                delete next[i];
            }
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }    
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        for(auto c : word)
        {
            if(c < 'a' || c > 'z')
            {
                return;
            }
        }
        
        TrieNode* p = root;
        for(auto c : word)
        {
            int i = c - 'a';
            
            if(p->next[i] == nullptr)
            {
                p->next[i] = new TrieNode();
            }
            
            p = p->next[i];
        }
        
        p->isExist = 1;
        
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* p = root;
        
        return dfs(p, word);
    }
    
    bool dfs(TrieNode* p, string str)
    {
        if(p == nullptr || str.size() <= 0)
        {
            return false;
        }
        
        char c = str[0];
        
        if(c >= 'a' && c <= 'z')
        {
            int i = c - 'a';
            
            if(p->next[i] == nullptr)
            {
                return false;
            }
            else
            {
                if(str.size() == 1)
                {
                    if(p->next[i]->isExist == 1)
                    {
                        return true;
                    }
                }
                else
                {
                    return dfs(p->next[i], str.substr(1));
                }
            }
        }
        else if(c == '.')
        {
            for(int i = 0; i<26; ++i)
            {
                if(p->next[i] != nullptr)
                {
                    if(str.size() == 1)
                    {
                        if(p->next[i]->isExist == 1)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        if(dfs(p->next[i], str.substr(1)))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
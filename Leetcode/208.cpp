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

class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode();
    }
    
        
    virtual ~Trie() 
    {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        for(auto c : word)
        {
            if(c < 'a' || c > 'z')
            {
                return false;
            }
        }
        
        TrieNode* p = root;
        for(auto c : word)
        {
            int i = c - 'a';
            
            if(p->next[i] == nullptr)
            {
                return false;
            }
            
            p = p->next[i];
        }
        
        if(p->isExist)
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given    prefix. */
    bool startsWith(string prefix) 
    {
        for(auto c : prefix)
        {
            if(c < 'a' || c > 'z')
            {
                return false;
            }
        }
        
        TrieNode* p = root;
        for(auto c : prefix)
        {
            int i = c - 'a';
            
            if(p->next[i] == nullptr)
            {
                return false;
            }
            
            p = p->next[i];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Trie
{
public:
    Trie():next(26,nullptr){}
    virtual ~Trie(){}
    vector<Trie*> next;
    priority_queue<string> suggest;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        
        for(auto &product : products)
        {
            Trie* p = root;
            
            for(auto c : product)
            {
                if(p->next[c - 'a'] == nullptr)
                {
                    p->next[c - 'a'] = new Trie;
                }
                
                p = p->next[c - 'a'];
                p->suggest.push(product);
                
                if(p->suggest.size() > 3)
                {
                    p->suggest.pop();
                }
            }
        }
        
        int len = searchWord.size();
        vector<vector<string>> ret(len, vector<string>());
        Trie* p = root;
            
        for(int i=0; i<len; ++i)
        {
            char c = searchWord[i];
            
            if(p->next[c - 'a'] == nullptr)
            {
                return ret;
            }
            
            p = p ->next[c - 'a'];
            
            while(!p->suggest.empty())
            {
                string t = p->suggest.top();
                p->suggest.pop();
                ret[i].push_back(t);
            }
            
            sort(ret[i].begin(), ret[i].end());
        }
        
        return ret;
    }
};
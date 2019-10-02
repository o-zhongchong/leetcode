struct Node
{
    int key;
    vector<Node*> next;
    Node(int val):key(val){}
};

class Skiplist {
public:
    Skiplist():MAX_LEVEL(10000) {
        head = new Node(0);
        head->next.push_back(nullptr);
        srand((unsigned)time(0));
    }
    
    bool search(int target) {
        int cur_level = head->next.size() - 1;
        Node *p = head;
        
        for(; cur_level >=0; --cur_level)
        {
            while(p->next[cur_level] != nullptr)
            {
                if(p->next[cur_level]->key < target)
                    p = p->next[cur_level];
                else if(p->next[cur_level]->key == target)
                    return true;
                else
                    break;
            }
        }
        
        return false;
    }
    
    void add(int num) {
        Node *node = new Node(num);
        int k = 0;
        bool coin_flip = rand() % 2;
        while( coin_flip && k< MAX_LEVEL)
        {
            ++k;
            coin_flip = rand() % 2;
        }
        node->next.insert(node->next.begin(),k+1,nullptr);
        
        int cur_level = head->next.size();
        if( k >= cur_level )
        {
            head->next.insert(head->next.end(), k-cur_level+1, nullptr);
        }
        
        Node *p = head;
        cur_level = k;
        for(; cur_level>=0; --cur_level )
        {
            while( p->next[cur_level] != nullptr &&
                 p->next[cur_level]->key < node->key )
            {
                p = p->next[cur_level];
            }
            
            node->next[cur_level] = p->next[cur_level];
            p->next[cur_level] = node;
        }
    }
    
    bool erase(int num) {
        int cur_level = head->next.size() - 1;
        Node *p = head;
        Node *target = nullptr;
        
        for(; cur_level >=0; --cur_level)
        {
            while(p->next[cur_level] != nullptr)
            {
                if( p->next[cur_level]->key < num )
                    p = p->next[cur_level];
                else if( p->next[cur_level]->key == num )
                {
                    if(target == nullptr)
                    {
                        target = p->next[cur_level];
                        p->next[cur_level] = p->next[cur_level]->next[cur_level];
                        break;
                    }
                    else
                    {
                        if( p->next[cur_level] == target )
                        {
                            p->next[cur_level] = p->next[cur_level]->next[cur_level];
                            break;
                        }
                        else
                        {
                            Node *s = p->next[cur_level];
                            while(s->next[cur_level] != target)
                                s = s->next[cur_level];
                            s->next[cur_level] = s->next[cur_level]->next[cur_level];
                            break;
                        }
                    }
                }
                else
                    break;
            }
        }
        
        if( target != nullptr)
        {
            delete target;
            return true;
        }
        return false;
    }
protected:
    Node *head;
    int MAX_LEVEL;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
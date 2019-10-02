const int MAX_LEVEL = 20;

struct Node
{
    int key;
    Node *next[MAX_LEVEL];
    Node(int val):key(val){}
};

class Skiplist {
public:
    Skiplist(){
        head = new Node(0);
        head->next[0] = nullptr;
        top_level=0;
        srand((unsigned)time(0));
    }
    
    bool search(int target) {
        int cur_level = top_level;
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
        int coin_flip = rand() % 4;
        while( coin_flip == 0 && k+1 < MAX_LEVEL)
        {
            ++k;
            coin_flip = rand() % 4;
        }
        for(int i=0; i<=k; ++i)
            node->next[i]=nullptr;
        
        if( k > top_level )
        {
            for(int i=top_level+1; i<=k; ++i)
                head->next[i]=nullptr;
            top_level = k;
        }
        
        Node *p = head;
        int cur_level = k;
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
        int cur_level = top_level;
        Node *p = head;
        Node* target = nullptr;
  
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
    int top_level;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
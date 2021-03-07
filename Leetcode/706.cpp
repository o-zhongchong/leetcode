class Node
{
public:
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        pre = nullptr;
    }
    ~Node(){}
    
    int key;
    int val;
    Node* next;
    Node* pre;
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap():data(100,nullptr){
        len = 100;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = key % 100;
        Node* p = data[pos];
        
        if(p == nullptr)
        {
            data[pos] = new Node(key, value);
            return;
        }
        
        while(p->key != key && p->next != nullptr)
        {
            p = p->next;
        }
        
        if(p->key == key)
        {
            p->val = value;
            return;
        }
        
        p->next = new Node(key, value);
        p->next->pre = p;
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = key % 100;
        Node* p = data[pos];
        
        if(p == nullptr)
        {
            return -1;
        }
        
        while(p->key != key && p->next != nullptr)
        {
            p = p->next;
        }
        
        if(p->key == key)   
        {
            return p->val;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = key % 100;
        Node* p = data[pos];
        
        if(p == nullptr)
        {
            return;
        }
        
        while(p->key != key && p->next != nullptr)
        {
            p = p->next;
        }
        
        if(p->key == key)
        {
            Node* pre = p->pre;
            
            if(pre != nullptr)
            {
                pre->next = p->next;
            }
            else
            {
                data[pos] = p->next;
            }
            
            if(p->next != nullptr)
            {
                p->next->pre = pre;
            }
            
            delete p;
        }
        
        return;
    }
    
protected:
    vector<Node*> data;
    int len;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */